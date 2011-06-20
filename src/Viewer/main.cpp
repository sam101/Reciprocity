#include <QApplication>
#include <QDebug>
#include <QtCore/QTextCodec>
#include <World/World.h>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    World::World w;

    qDebug() << w.getChunk(-1,-1)->getTile(-30,-30).getX() << w.getChunk(-1,-1)->getTile(-30,-30).getY();


    return a.exec();
}
