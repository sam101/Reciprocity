#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>
namespace Server
{
    /**
      * Gère la connexion et la deconnexion de clients
      * @brief Gère la connexion et la deconnexion de clients
      * @author Sam101
      */
    class ClientHandler : public QObject
    {
        Q_OBJECT
        protected:
        public:
            /**
              * Constructeur
              */
            ClientHandler();

        signals:
            /**
              * Envoyé pour signaler qu'un nouveau client s'est connecté
              */
            void newClient(QTcpSocket *socket);
        public slots:
            /**
              * Appelé quand un client se connecte au serveur.
              * Envoie la connexion au serveur si celle-ci
              * n'est pas filtrée
              */
            void handleIncomming();
    };
}
#endif //SERVER_CLIENTHANDLER_H
