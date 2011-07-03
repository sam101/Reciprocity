#include <QtGui/QApplication>
#include <GUI/StartWindow.h>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    //On construit la fenêtre de départ
    GUI::StartWindow *window = new GUI::StartWindow;
    window->show();

    return a.exec();
}
