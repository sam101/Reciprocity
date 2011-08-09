#include <Server/MessageSender.h>
#include <Network/ChunkDataMessage.h>
#include <Network/EntityDataMessage.h>
#include <Network/GameHasBegunMessage.h>
#include <Network/LoginFailedMessage.h>
#include <Network/LoginSuccessMessage.h>
#include <Network/MessageInMessage.h>
#include <Network/ServerDataMessage.h>
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
        Q_UNUSED(login)
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
    /**
      * Envoie les informations du serveur à un client
      */
    void MessageSender::sendServerData(QTcpSocket *socket)
    {
        //On construit le message
        //TODO: Ajouter nom serveur
        Network::ServerDataMessage m("");
        //On parcours la liste des clients
        QMutableMapIterator<QTcpSocket*, Server::Client*> it(_clients);
        while (it.hasNext())
        {
            Client *c = it.next().value();
            if (c->isOnline())
            {
                m.addPlayer(c->getLogin(),c->getPlayer()->isAdmin());
            }
        }
        //On construit le byteArray
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::SERVER_DATA;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On envoie le message
        socket->write(b);

    }
    /**
      * Envoie le message de début de parties à un client
      */
    void MessageSender::sendGameHasBegun(QTcpSocket *socket)
    {
        //On construit le message
        Network::GameHasBegunMessage m;
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::GAME_HAS_BEGUN;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);
    }
    /**
      * Envoie le message de début de partie à tout les clients
      */
    void MessageSender::sendGameHasBegunToAll()
    {
        //On itère sur tout les clients.
        QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
        while (it.hasNext())
        {
            Client *c = it.next().value();
            sendGameHasBegun(c->getSocket());
        }
    }
    /**
      * Envoie les informations sur un chunk
      */
    void MessageSender::sendChunkData(QTcpSocket *socket, Chunk::Chunk *chunk)
    {
        //On construit le message
        Network::ChunkDataMessage m(*chunk);
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::CHUNKDATA;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);
    }
    /**
      * Envoie les informations sur une entité
      */
    void MessageSender::sendEntityData(QTcpSocket *socket, Map::Entity *entity)
    {
        //On construit le message
        Network::EntityDataMessage m(*entity);
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::ENTITYDATA;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie
        socket->write(b);
    }
    /**
      * Envoie les informations à un joueur sur les chunk qu'il peut
      * voir ainsi que sur ses entités
      */
    void MessageSender::sendPlayerData(QTcpSocket *socket)
    {
        //On recupère la liste des chunk sur lesquels le joueur à des entités.
        QSet<Chunk::Chunk*> chunks = _game->getPlayerChunks(_clients[socket]->getPlayer());
        //On itère pour recupérer tout les chunks.
        QSetIterator<Chunk::Chunk*> it(chunks);

        while (it.hasNext())
        {
            sendChunkData(socket,it.next());
        }
        //On envoie toutes les entités.
    }
}
