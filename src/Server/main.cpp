#include <QtCore/QCoreApplication>
#include <QtCore/QTextCodec>

#include <ctime>

#include <Config/BaseConfig.h>
#include <Server/Server.h>
#include <Tools/Random.h>
#include <QtCore/QStringList>
using namespace Tools;
using namespace Config;
int main(int argc, char *argv[])
{
    //On construit l'objet application.
    QCoreApplication a(argc,argv);
    //On déclare les variables pour le port/nom du serveur
    qint32 serverPort = BaseConfig::SERVER_PORT;
    QString name = QObject::tr("Yet another Reciprocity server");
    //On initialise Random
    Random::init(time(NULL));
    //On parse les arguments passés à la ligne de commande
    QStringList args = a.arguments();
    for (int i = 0; i < args.size(); i++)
    {
        //On gère le port du serveur
        if (args[i] == "-port" && i != (args.size() - 1))
        {
            serverPort = args.at(i + 1).toInt();
        }
        //On gère le nom du serveur
        else if (args[i] == "-name" && i != (args.size() - 1))
        {
            name = args[i + 1];
        }
    }
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
