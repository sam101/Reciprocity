#include <Server/MessageSender.h>
#include <Network/LoginFailedMessage.h>
#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
namespace Server
{
    /**
      * Envoie un message comme quoi le login demandé par le client
      * existe déjà
      */
    void MessageSender::sendLoginAlreadyExists(QTcpSocket *socket, QString login)
    {
        //On construit le message
        Network::LoginFailedMessage m(Network::LoginFailedMessage::LOGIN_ALREADY_EXIST);
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(b);
        in << (qint32)0;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);
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
