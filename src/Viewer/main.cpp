#include <QtGui/QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTextCodec>

#include <ctime>

#include <Tools/Random.h>
#include <Viewer/ViewerView.h>
#include <World/World.h>
using namespace Tools;

int main(int argc, char *argv[])
{
    //On déclare l'objet application
    QApplication a(argc,argv);
    //On passe toutes les chaines en UTF-8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //On initialise l'objet aléatoire
    Random::init(time(NULL));
    //On initialise provider
    //On déclare une ViewverView (TODO: Faire une MainWindow)
    Viewer::ViewerView *view = new Viewer::ViewerView;
    //On l'affiche
    view->show();


    return a.exec();
}
