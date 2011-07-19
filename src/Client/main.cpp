#include <QtGui/QApplication>
#include <QtCore/QTextCodec>

#include <Client/ConnectionHandler.h>
#include <GUI/ConnectingWindow.h>
#include <GUI/JoinGameWindow.h>
#include <GUI/StartWindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    //On indique que l'application utilise UTF-8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

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
    //On connecte les signaux pour les erreurs.
    QObject::connect(connectionHandler,SIGNAL(hostnameNotFound()),connectingWindow,SLOT(hostNotFoundError()));
    QObject::connect(connectionHandler,SIGNAL(badPort()),connectingWindow,SLOT(unknownErrorOccurred()));
    QObject::connect(connectionHandler,SIGNAL(unknownError()),connectingWindow,SLOT(unknownErrorOccurred()));
    QObject::connect(connectionHandler,SIGNAL(connectionRefused()),connectingWindow,SLOT(connectionRefusedError()));

    //On execute l'application
    return a.exec();
}
