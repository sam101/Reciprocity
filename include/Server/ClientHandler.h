#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H
#include <Server/Client.h>
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
            /**
              * Référence vers le Map des clients.
              */
        QMap<QTcpSocket*,Client*>& _clients;
        public:
            /**
              * Constructeur
              */
            ClientHandler(QMap<QTcpSocket*,Client*>& clients);
            /**
              * Renvoie le nombre de clients actuellement connectés
              */
            qint32 getClientsOnline() const;
        signals:
            /**
              * Envoyé pour signaler qu'un nouveau client s'est connecté
              */
            void newClient(QTcpSocket *socket);
            /**
              * Envoyé pour signaler qu'un client s'est deconnecté
              */
            void clientHasDisconnected(QTcpSocket *socket);
        public slots:
            /**
              * Appelé quand un client se connecte au serveur.
              * Envoie la connexion au serveur si celle-ci
              * n'est pas filtrée
              */
            void handleIncomming();
            /**
              * Appelé quand un client se deconnecte du serveur.
              * Envoit un signal pour annoncer que le client
              * s'est déconnecté
              */
            void handleDisconnection();
            /**
              * Deconnecte un client (pour message incorrect)
              */
            void kickIncorrectClient(QTcpSocket*);
            /**
              * Deconnecte un client kické
              */
            void kickPlayer(QString login);

    };
}
#endif //SERVER_CLIENTHANDLER_H
