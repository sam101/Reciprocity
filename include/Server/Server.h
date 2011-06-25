#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include <Config/Config.h>
#include <QtCore/QObject>
#include <QtNetwork/QTcpServer>
namespace Server
{
    /**
      * Classe de base gérant le serveur
      * @brief Classe de base gérant le serveur
      * @author Sam101
      */
    class Server : public QObject
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers la socket serveur
              */
            QTcpServer *_socketServer;
       public:
            /**
              * Constructeur
              */
            Server(qint32 port = Config::Config::SERVER_PORT);

    };
}
#endif //SERVER_SERVER_H
