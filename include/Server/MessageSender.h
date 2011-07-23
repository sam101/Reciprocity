#ifndef SERVER_MESSAGESENDER_H
#define SERVER_MESSAGESENDER_H
#include <Network/AbstractMessage.h>
#include <Server/Client.h>

#include <QtNetwork/QTcpSocket>

#include <QtCore/QMap>
#include <QtCore/QObject>
namespace Server
{
    /**
      * S'occupe d'envoyer les différants messages aux clients
      * @brief S'occupe d'envoyer les différants messages aux clients
      * @author Sam101
      */
    class MessageSender : public QObject
    {
        Q_OBJECT
        protected:
            /**
              * Map des clients
              */
            QMap<QTcpSocket*, Client*> &_clients;
        public:
            /**
              * Constructeur
              */
            MessageSender(QMap<QTcpSocket*,Client*> &clients);
        public slots:
            /**
              * Envoie un message comme quoi le login demandé par le client
              * existe déjà
              */
            void sendLoginAlreadyExists(QTcpSocket *socket, QString login);
            /**
              * Envoie un message au client comme quoi un login à réussi
              */
            void sendLoginSuccess(QTcpSocket *socket, qint32 id, bool isAdmin);
            /**
              * Envoie un message aux clients
              */
            void sendChatMessage(QString dest, QString contents, QString sender);
    };
}
#endif //SERVER_MESSAGESENDER_H
