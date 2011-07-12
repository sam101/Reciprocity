#ifndef SERVER_MESSAGESENDER_H
#define SERVER_MESSAGESENDER_H
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>
#include <Network/AbstractMessage.h>
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

        public slots:
            /**
              * Envoie un message comme quoi le login demandé par le client
              * existe déjà
              */
            void sendLoginAlreadyExists(QTcpSocket *socket, QString login);
            /**
              * Envoie un message au client comme quoi un login à réussi
              */
            void sendLoginSuccess(QTcpSocket *socket, qint32 id);
    };
}
#endif //SERVER_MESSAGESENDER_H
