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

    w.getChunk(-1,1);
    qDebug () << "1";
    w.getChunk(-1,-1);
    qDebug () << "1";
    w.getChunk(1,-1);
    qDebug () << "1";
    w.getChunk(1,1);
    qDebug () << "1";

    return a.exec();
}
