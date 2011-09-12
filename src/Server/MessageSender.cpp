#include <Server/MessageSender.h>
#include <Network/ChunkDataMessage.h>
#include <Network/EntityDataMessage.h>
#include <Network/GameHasBegunMessage.h>
#include <Network/KickMessage.h>
#include <Network/LoginFailedMessage.h>
#include <Network/LoginSuccessMessage.h>
#include <Network/MessageInMessage.h>
#include <Network/MoveUnitAcceptedMessage.h>
#include <Network/NewTurnMessage.h>
#include <Network/ServerDataMessage.h>
#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>
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
        qDebug() << "Envoi des informations sur le serveur à " << socket->peerAddress().toString();
        //On construit le message
        //TODO: Ajouter nom serveur
        Network::ServerDataMessage m("",_game->getTurn());
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
      * Envoie les informations du serveur à tous
      */
    void MessageSender::sendServerDataToAll()
    {
        //On construit le message
        //TODO: Ajouter nom serveur
        Network::ServerDataMessage m("",_game->getTurn());
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
        //On l'envoie à tout les clients
        //On l'envoie à tout les clients
        QMutableMapIterator<QTcpSocket*, Client*> it2(_clients);
        while (it2.hasNext())
        {
            Client *c = it2.next().value();
            if (c->isOnline())
            {
                c->getSocket()->write(b);
            }
        }
    }

    /**
      * Envoie le message de début de parties à un client
      */
    void MessageSender::sendGameHasBegun(QTcpSocket *socket)
    {
        qDebug() << "Envoi de GameBasBegun a " << socket->peerAddress().toString();
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
        if (chunk == NULL)
        {
            return;
        }
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
        socket->flush();
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
        qDebug() << "Envoi des informations de joueur a " << socket->peerAddress().toString();
        //On recupère la liste des chunk sur lesquels le joueur à des entités.
        QSet<Chunk::Chunk*> chunks = _game->getPlayerChunks(_clients[socket]->getPlayer());
        //On itère pour recupérer tout les chunks.
        QSetIterator<Chunk::Chunk*> it(chunks);

        while (it.hasNext())
        {
            sendChunkData(socket,it.next());
        }
        //On envoie toutes les entités.
        QList<Map::Entity*> e = _game->getPlayerEntities(_clients[socket]->getPlayer());
        for (int i = 0; i < e.size(); i++)
        {
            sendEntityData(socket,e[i]);
        }
    }
    /**
      * Envoie une information comme quoi un joueur a été kické
      */
    void MessageSender::sendKickMessage(QString login)
    {
        //On construit le message
        Network::KickMessage m(login);
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::KICK;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie à tout les clients
        QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
        while (it.hasNext())
        {
            Client *c = it.next().value();
            if (c->isOnline())
            {
                c->getSocket()->write(b);
            }
        }

    }
    /**
      * Envoie l'information comme quoi une entité à bougé
      */
    void MessageSender::sendEntityHasMoved(QTcpSocket *socket, Map::Entity *entity)
    {
        //On construit le message
        Network::MoveUnitAcceptedMessage m(entity->getId(),entity->getX(),entity->getY());
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)Network::MOVEUNIT_ACCEPTED;
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On envoie le message
        socket->write(b);
        //On envoie les informations de l'entité.
        sendEntityData(socket,entity);
    }
    /**
      * Envoie l'information de nouveau tour aux joueurs
      */
    void MessageSender::sendNewTurnToAll()
    {
        //On construit le message
        Network::NewTurnMessage m(_game->getTurn());
        //On construit le byteArray dans lequel le mettre
        QByteArray b;
        QDataStream in(&b,QIODevice::WriteOnly);
        in << (qint32)0;
        in << (qint32)m.getType();
        in << m;
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On l'envoie à tout les clients
        QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
        while (it.hasNext())
        {
            Client *c = it.next().value();
            if (c->isOnline())
            {
                c->getSocket()->write(b);
            }
        }
    }
    /**
      * Envoie les informations  à tout les joueurs
      */
    void MessageSender::sendPlayerDataToAll()
    {
        Client *c;
        QMutableMapIterator<QTcpSocket*, Client*> it(_clients);
        while (it.hasNext())
        {
            c = it.next().value();
            if (c->isOnline())
            {
                sendPlayerData(c->getSocket());
            }
        }
    }
    /**
      * Envoie les informations sur le fait qu'un batiment a été construit au joueur
      */
    void MessageSender::sendBuildingBuilt(QTcpSocket *socket, qint32 entityId)
    {
        //TODO
    }
}
