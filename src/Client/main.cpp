#include <QtGui/QApplication>
#include <GUI/JoinGameWindow.h>
#include <GUI/StartWindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    //On construit la fenêtre de départ
    GUI::StartWindow *window = new GUI::StartWindow;
    window->show();
    //On construit la fenêtre pour rejoindre un client.
    GUI::JoinGameWindow *joinGameWindow = new GUI::JoinGameWindow;
    //On la connecte à la fenêtre de départ.
    QObject::connect(window,SIGNAL(joinGameRequested()),joinGameWindow,SLOT(show()));

    //On execute l'application
    return a.exec();
}
