#include <Server/MessageSender.h>
#include <Network/LoginFailedMessage.h>
#include <Network/LoginSuccessMessage.h>
#include <Network/MessageInMessage.h>
#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
namespace Server
{
    /**
      * Constructeur
      */
    MessageSender::MessageSender(QMap<QTcpSocket *, Client *> &clients) :
    _game(NULL),
    _clients(clients)
    {

    }
    /**
      * Change l'objet de jeu actuel
      */
    void MessageSender::setGame(Game::Game *game)
    {
        _game = game;
    }
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
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::LOGIN_FAILED;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);
    }
    /**
      * Envoie un message au client comme quoi un login à réussi
      */
    void MessageSender::sendLoginSuccess(QTcpSocket *socket, qint32 id, bool isAdmin)
    {
        //On construit le message
        Network::LoginSuccessMessage m(id,isAdmin);
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::LOGIN_SUCCESS;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);

    }
    /**
      * Envoie un message aux clients
      */
    void MessageSender::sendChatMessage(QString dest, QString contents, QString sender)
    {
        //On construit le message tout d'abord.
        Network::MessageInMessage m(sender,contents);
        //On construit le bytearray
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::MESSAGE_IN;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie aux clients visés.
        if (dest == "")
        {
            //Si le destinataire est vide, on envoie à tout les clients.
            QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
            while (it.hasNext())
            {
                Client *c = it.next().value();
                c->getSocket()->write(b);
            }
        }
        else
        {
            //Sinon, on l'envoie au client visé.
            QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
            while (it.hasNext())
            {
                Client *c = it.next().value();
                if (c->getLogin() == dest)
                {
                    c->getSocket()->write(b);
                    return;
                }
            }
        }
    }
}
