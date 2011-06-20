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

    for (int i = -31; i < 32 ; i++)
    {
        for (int j = -31; j < 32; j++)
        {
            qDebug() << "Tile:" << j << i << w.getTile(j,i).getX() << w.getTile(j,i).getY();
        }
    }

    return a.exec();
}
