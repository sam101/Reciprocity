#include <QtCore/QCoreApplication>
#include <QtCore/QTextCodec>
#include <Server/Server.h>
int main(int argc, char *argv[])
{
    //On construit l'objet application.
    QCoreApplication a(argc,argv);
    //On déclare qu'on utilise UTF-8.
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //On construit un objet serveur.
    Server::Server *server = new Server::Server;
    server->init();
    //On execute l'application
    return a.exec();
}
