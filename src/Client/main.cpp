#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
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
    QObject::connect(joinGameWindow,SIGNAL(wantToConnect(QString,qint32,QString,QString)),connectingWindow,SLOT(start(QString,qint32,QString,QString)));

    //On execute l'application
    return a.exec();
}
