#include <QtGui/QApplication>
#include <QtCore/QDebug>
#include <QtCore/QTextCodec>

#include <ctime>

#include <Tools/Random.h>
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

    //Tests.
    World::World w;

    w.getChunk(1,1);


    return a.exec();
}
