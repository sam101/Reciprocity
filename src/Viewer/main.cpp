#include <QApplication>
#include <QDebug>
#include <World/World.h>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    World::World w;

    qDebug() << w.getChunk(-1,1)->getTile(0,0).getX();

    return a.exec();
}
