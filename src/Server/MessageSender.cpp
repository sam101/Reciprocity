#include <Server/MessageSender.h>
namespace Server
{
    /**
      * Envoie un message comme quoi le login demandé par le client
      * existe déjà
      */
    void MessageSender::sendLoginAlreadyExists(QTcpSocket *socket, QString login)
    {
        //TODO
        Q_UNUSED(socket)
        Q_UNUSED(login)
    }
    /**
      * Envoie un message au client comme quoi un login à réussi
      */
    void MessageSender::sendLoginSuccess(QTcpSocket *socket, qint32 id)
    {
        //TODO
        Q_UNUSED(socket)
        Q_UNUSED(id)
    }
}
