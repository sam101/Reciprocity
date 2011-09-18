#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <ctime>

#include <Client/Client.h>
#include <Client/ConnectionHandler.h>
#include <Graphics/Provider.h>
#include <GUI/ConnectingWindow.h>
#include <GUI/GameWindow.h>
#include <GUI/JoinGameWindow.h>
#include <GUI/StartWindow.h>
#include <GUI/WaitingWindow.h>
#include <Tools/ClientSettings.h>
#include <Tools/Random.h>
#include <QtCore/QStringList>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    //On indique que l'application utilise UTF-8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    //On définit le chemin par défaut des données
    QString dataPath = "../Reciprocity/data";
    //On reucpère les arguments passés
    QStringList args = a.arguments();
    //On parse les arguments
    for (int i = 0; i < args.size(); i++)
    {
        //On teste le cas où l'utilisateur souhaite spécifier le chemin vers les données
        if (args[i] == "-datapath" && i != (args.size() - 1))
        {
            dataPath = args[i + 1];
        }
    }
    //On initialise Provider
    Graphics::Provider::init(dataPath);
    //On initialise l'objet de paramètres
    Tools::ClientSettings::init();
    //On initialise le générateur de nombres pseudo-aléatoires
    Tools::Random::init(time(NULL));
    //On construit la fenêtre de départ
    GUI::StartWindow *window = new GUI::StartWindow;
    window->show();

    //On construit la fenêtre pour rejoindre un client.
    GUI::JoinGameWindow *joinGameWindow = new GUI::JoinGameWindow;
    //On la connecte à la fenêtre de départ.
    QObject::connect(window,SIGNAL(joinGameRequested()),joinGameWindow,SLOT(show()));

    //On construit la fenêtre d'attente à la connexion.
    GUI::ConnectingWindow *connectingWindow = new GUI::ConnectingWindow;
    //On connecte les signaux de joinGame à la fenêtre d'attente.
    QObject::connect(joinGameWindow,SIGNAL(wantToConnect(QString,qint32,QString,QString)),connectingWindow,SLOT(start(QString,qint32,QString,QString)));

    //On construit le ConnectionHandler.
    Client::ConnectionHandler *connectionHandler = new Client::ConnectionHandler;
    //On connecte le signal pour la connexion
    QObject::connect(joinGameWindow,SIGNAL(wantToConnect(QString,qint32,QString,QString)),connectionHandler,SLOT(startConnection(QString,qint32,QString,QString)));
    //On connecte les signaux d'état pour ConnectingWindow
    QObject::connect(connectionHandler,SIGNAL(hostFound()),connectingWindow,SLOT(hostFoundMessage()));
    QObject::connect(connectionHandler,SIGNAL(connectedToServer()),connectingWindow,SLOT(connectedMessage()));
    QObject::connect(connectionHandler,SIGNAL(loginSuccess()),connectingWindow,SLOT(loginSuccessMessage()));
    //On connecte les signaux pour les erreurs.
    QObject::connect(connectionHandler,SIGNAL(hostnameNotFound()),connectingWindow,SLOT(hostNotFoundError()));
    QObject::connect(connectionHandler,SIGNAL(badPort()),connectingWindow,SLOT(unknownErrorOccurred()));
    QObject::connect(connectionHandler,SIGNAL(unknownError()),connectingWindow,SLOT(unknownErrorOccurred()));
    QObject::connect(connectionHandler,SIGNAL(connectionRefused()),connectingWindow,SLOT(connectionRefusedError()));
    QObject::connect(connectionHandler,SIGNAL(loginFailedError()),connectingWindow,SLOT(loginFailedError()));

    //On construit la WaitingWindow
    GUI::WaitingWindow *waitingWindow = new GUI::WaitingWindow;
    //On connecte les signaux
    QObject::connect(connectionHandler,SIGNAL(clientHasChanged(QObject*)),waitingWindow,SLOT(setClient(QObject*)));
    QObject::connect(connectionHandler,SIGNAL(loginSuccess()),waitingWindow,SLOT(show()));

    //On construit la fenêtre de jeu
    GUI::GameWindow *gameWindow = new GUI::GameWindow;
    //On connecte les signaux
    QObject::connect(connectionHandler,SIGNAL(clientHasChanged(QObject*)),gameWindow,SLOT(setClient(QObject*)));
    QObject::connect(waitingWindow,SIGNAL(gameHasBegun()),gameWindow,SLOT(beginGame()));
    //On execute l'application
    return a.exec();
}
