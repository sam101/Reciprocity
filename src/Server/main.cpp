#include <QtCore/QCoreApplication>
#include <QtCore/QTextCodec>
#include <ctime>
#include <Server/Server.h>
#include <Tools/Random.h>
using namespace Tools;
int main(int argc, char *argv[])
{
    //On construit l'objet application.
    QCoreApplication a(argc,argv);
    //On déclare les variables pour le port/nom du serveur
    qint32 serverPort = Config::Config::SERVER_PORT;
    QString name = QObject::tr("Yet another Reciprocity server");
    //On initialise Random
    Random::init(time(NULL));
    //On déclare qu'on utilise UTF-8.
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //On affiche un message
    qDebug() << "Serveur de Reciprocity - Version de dev (git)";
    //On construit un objet serveur.
    Server::Server *server = new Server::Server;
    server->init(serverPort,name);
    //On execute l'application
    return a.exec();
}
