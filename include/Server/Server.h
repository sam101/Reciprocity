#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include <Config/Config.h>
#include <Game/Game.h>
#include <Server/Client.h>
#include <Server/ClientHandler.h>

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
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
              * Map des clients présents sur le serveur
              */
            QMap<QTcpSocket*,Client*> _clients;
            /**
              * Pointeur vers la socket serveur
              */
            QTcpServer *_socketServer;
            /**
              * Pointeur vers le ClientHandler
              */
            ClientHandler *_clientHandler;
            /**
              * Pointeur vers l'objet de jeu actuel
              */
            Game::Game *_game;
       public:
            /**
              * Constructeur
              */
            Server(qint32 port = Config::Config::SERVER_PORT);
            /**
              * Destructeur
              */
            virtual ~Server();
            /**
              * Initialise le serveur et commence l'écoute.
              */
            void init(qint32 port = Config::Config::SERVER_PORT);
    };
}
#endif //SERVER_SERVER_H
