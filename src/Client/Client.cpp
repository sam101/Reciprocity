#include <Client/Client.h>
#include <Config/Config.h>
#include <Network/BeginGameMessage.h>
#include <Network/BuildMessage.h>
#include <Network/BuildAcceptedMessage.h>
#include <Network/ChunkDataMessage.h>
#include <Network/EndTurnMessage.h>
#include <Network/EntityDataMessage.h>
#include <Network/GameHasBegunMessage.h>
#include <Network/GetServerDataMessage.h>
#include <Network/LoginMessage.h>
#include <Network/LoginSuccessMessage.h>
#include <Network/MessageInMessage.h>
#include <Network/MessageOutMessage.h>
#include <Network/MoveUnitMessage.h>
#include <Network/MoveUnitAcceptedMessage.h>
#include <Network/NewTurnMessage.h>
#include <Network/RequestDataMessage.h>
#include <Network/ServerDataMessage.h>
#include <Network/WorkMessage.h>
#include <Network/WorkAcceptedMessage.h>
#include <QtCore/QDataStream>
#include <QtCore/QDebug>
namespace Client
{
    /**
      * Constructeur
      */
    Client::Client(QTcpSocket *socket, QString login, QString hash) :
    _dataHandler(NULL),
    _socket(socket),
    _messageSize(0),
    _gameHasBegun(false),
    _isLogged(false),
    _isAdmin(false),
     _id(-1),
    _turn(0),
    _login(login),
    _hash(hash)
    {
        //On construit le dataHandler
        _dataHandler = new DataHandler;
        //On connecte les signaux du socket
        connect(_socket,SIGNAL(readyRead()),this,SLOT(messageRecevied()));
        connect(_socket,SIGNAL(disconnected()),this,SLOT(hasDisconnected()));
    }
    /**
      * Renvoie le DataHandler
      */
    DataHandler* Client::getDataHandler()
    {
        return _dataHandler;
    }
    /**
      * Renvoie le DataHandler
      * surchargé constant
      */
    const DataHandler* Client::getDataHandler() const
    {
        return _dataHandler;
    }
    /**
      * Renvoie l'id du client
      */
    qint32 Client::getId() const
    {
        return _id;
    }
    /**
      * Renvoie le login du client
      */
    QString Client::getLogin() const
    {
        return _login;
    }
    /**
      * Renvoie le hash du client
      */
    QString Client::getHash() const
    {
        return _hash;
    }
    /**
      * Renvoie si le joueur est admin
      */
    bool Client::isAdmin() const
    {
        return _isAdmin;
    }
    /**
      * Gère la deconnexion du serveur
      */
    void Client::hasDisconnected()
    {
        emit serverHasDisconnected();
    }
    /**
      * Envoie un message de login
      */
    void Client::sendLoginMessage()
    {
        //On construit le message
        Network::LoginMessage loginMessage(0,_login,_hash);

        //On déclare le byteArray qui stockera les infos du message
        QByteArray b;
        //On déclare le flux dans lequel écrire.
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)Network::LOGIN;
        //On écrit le message
        in << loginMessage;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }
    /**
      * Envoie le message de demande des informations au serveur
      */
    void Client::sendGetServerData()
    {
        //On construit le message
        Network::GetServerDataMessage m;
        //On déclare le byteArray qui stockera les infos du message
        QByteArray b;
        //On déclare le flux dans lequel écrire.
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)Network::GET_SERVER_DATA;
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }

    /**
      * Envoie un message de début de partie
      */
    void Client::sendBeginGame()
    {
        /*
         * On vérifie que le joueur est administrateur
         */
        if (_isAdmin)
        {
            //On construit le message
            Network::BeginGameMessage m;
            //On déclare le byteArray qui stockera les infos du message
            QByteArray b;
            //On déclare le flux dans lequel écrire.
            QDataStream in(&b,QIODevice::WriteOnly);
            in.setVersion(QDataStream::Qt_4_5);
            //On écrit la taille vide
            in << (qint32)0;
            //On écrit le type du message
            in << (qint32)Network::BEGIN_GAME;
            //On écrit le message
            in << m;
            //On écrit la bonne taille
            in.device()->seek(0);
            in << (qint32)(b.size() - sizeof(qint32));
            //On écrit le message
            _socket->write(b);
        }
        else
        {
            qDebug() << "Tentative d'envoi d'un message de commencement de partie sans être administrateur avortée.";
        }

    }
    /**
      * Envoie un message aux autres joueurs
      */
    void Client::sendChatMessage(QString contents)
    {
        //On construit le message
        Network::MessageOutMessage m(contents);
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)Network::MESSAGE_OUT;
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }
    /**
      * Envoie une demande de données au serveur
      */
    void Client::sendRequestData()
    {
        //On construit le message
        Network::RequestDataMessage m;
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)Network::REQUEST_DATA;
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);

    }
    /**
      * Envoie une demande de déplacement
      */
    void Client::sendMoveUnit(qint32 id, qint32 x, qint32 y)
    {
        /*
         * TODO: Ajouter que le voyage DOIT être possible:
         * Tant qu'a faire, autant pas ennuyer le serveur
         */
        //On construit le message
        Network::MoveUnitMessage m(id,x,y);
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)m.getType();
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }
    /**
      * Envoie une demande de fin de tour
      */
    void Client::sendEndTurn()
    {
        //On construit le message
        Network::EndTurnMessage m(_login);
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << (qint32)m.getType();
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }
    /**
      * Envoie une demande de construction de batiment
      */
    void Client::sendBuild(qint32 entity, Map::BuildingType type)
    {
        //On construit le message
        Network::BuildMessage m(entity,type);
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << Network::BUILD;
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }
    /**
      * Envoie une demande de travail sur une entité
      */
    void Client::sendWork(qint32 entity)
    {
        //On construit le message
        Network::WorkMessage m(entity);
        //on construit le byteArray
        QByteArray b;
        //On déclare le flux dans lequel écrire
        QDataStream in(&b,QIODevice::WriteOnly);
        in.setVersion(QDataStream::Qt_4_5);
        //On écrit la taille vide
        in << (qint32)0;
        //On écrit le type du message
        in << Network::WORK;
        //On écrit le message
        in << m;
        //On écrit la bonne taille
        in.device()->seek(0);
        in << (qint32)(b.size() - sizeof(qint32));
        //On écrit le message
        _socket->write(b);
    }

    /**
      * Appelé quand le client reçoit un message du socket
      */
    void Client::messageRecevied()
    {
        //On vérifie que c'est bien la socket qui a envoyé le message
        if (qobject_cast<QTcpSocket*>(sender()) != _socket)
        {
            qDebug() << "Erreur: messageRecevied() appellé par autre chose que la socket";
            return;
        }
        //On déclare un QDataStream pour lire les données
        QDataStream in(_socket);
        in.setVersion(QDataStream::Qt_4_5);
        while (_socket->bytesAvailable() >= _messageSize)
        {
            //On vérifie si on a pas déjà reçu la taille du message
            if (_messageSize == 0)
            {
                //On vérifie qu'on à bien reçu la taille
                if (_socket->bytesAvailable() < (qint32)sizeof(qint32) )
                {
                    return;
                }
                //On recupère la taille
                in >> _messageSize;
                //On vérifie que la taille est correcte
                if (_messageSize < 0)
                {
                    qDebug() << "Erreur: Message incorrect reçu";
                    _messageSize = 0;

                    emit incorrectMessage();

                    return;
                }
            }
            if (_socket->bytesAvailable() < _messageSize)
            {
                return;
            }
            //On recupère le type du message
            qint32 type;
            in >> type;
            qDebug() << "Message reçu du serveur de type " << type << "et de taille" << _messageSize ;
            //On remet à zéro la taille du message
            _messageSize = 0;
            //On gère selon le type
            switch (type)
            {
                //Si le login est reussi...
                case Network::LOGIN_SUCCESS:
                    handleLoginSuccess(in);
                break;
                //Si le login a échoué.
                case Network::LOGIN_FAILED:
                    emit loginFailed();
                break;
                //Si on a reçu un message de chat
                case Network::MESSAGE_IN:
                    handleChatMessage(in);
                break;
               //Si on a reçu les informations du serveur
               case Network::SERVER_DATA:
                    handleServerData(in);
               break;
               //Si on a reçu le message de début de partie
               case Network::GAME_HAS_BEGUN:
                    handleGameHasBegun(in);
               break;
               //Si on a reçu des informations de chunk
               case Network::CHUNKDATA:
                    handleChunkData(in);
               break;
               //Si on a reçu des informations sur des entités
               case Network::ENTITYDATA:
                    handleEntityData(in);
               break;
               case Network::MOVEUNIT_ACCEPTED:
                    handleMoveUnitAccepted(in);
               break;
               case Network::BUILD_ACCEPTED:
                    handleBuildAccepted(in);
               break;
               case Network::WORK_ACCEPTED:
                    handleWorkAccepted(in);
               break;
               case Network::NEWTURN:
                    handleNewTurn(in);
                break;
               //Sinon, on lit juste les données pour les libérer
               default:
                    _socket->read(_messageSize);
            }
        }
    }

    /**
      * Gère le login du joueur
      */
    void Client::handleLoginSuccess(QDataStream &in)
    {
        //On Recupère le message
        Network::LoginSuccessMessage m;
        in >> m;
        //On met à jour les données
        _isLogged = true;
        _isAdmin = m.isAdmin();
        _id = m.getId();
        //On emet le signal
        emit loginSuccess();
    }
    /**
      * Gère la reception d'un message
      */
    void Client::handleChatMessage(QDataStream &in)
    {
        //On recupère le message
        Network::MessageInMessage m;
        in >> m;
        //On emet le signal comme quoi on a reçu un message.
        emit messageRecevied(m.getSender(),m.getContents());
    }
    /**
      * Gère la reception des informations du serveur
      */
    void Client::handleServerData(QDataStream &in)
    {
        //On recupère le message
        Network::ServerDataMessage m;
        in >> m;
        //On met à jour la liste des joueurs
        _dataHandler->getPlayers() = m.getPlayers();
        //On met à jour le numéro du tour
        _turn = m.getTurn();
        //On emet le signal comme quoi la liste des joueurs a été mise à jour
        emit playerListHasBeenUpdated(_dataHandler->getPlayers());
        emit turnNumberHasChanged(_turn);
    }
    /**
      * Gère la reception d'un message de début de partie
      */
    void Client::handleGameHasBegun(QDataStream &in)
    {
        qDebug() << "Le message de début de partie a été reçu";
        //On recupère le message
        Network::GameHasBegunMessage m;
        in >> m;
        //On envoie le signal comme quoi la partie à commencé
        _gameHasBegun = true;
        emit gameHasBegun();
    }
    /**
      * Gère la reception de données de chunk
      */
    void Client::handleChunkData(QDataStream &in)
    {
        //On recupère les données
        Network::ChunkDataMessage m;
        in >> m;
        //On traite les données
        _dataHandler->addChunk(m.getChunk());
    }
    /**
      * Gère la reception de données sur des entités
      */
    void Client::handleEntityData(QDataStream &in)
    {
        //On recupère les données
        Network::EntityDataMessage m;
        in >> m;
        //On traite les données
        _dataHandler->addEntity(m.getEntity());
    }
    /**
      * Gère la réception d'une acceptation d'entité déplacée
      */
    void Client::handleMoveUnitAccepted(QDataStream &in)
    {
        //On recupère le message
        Network::MoveUnitAcceptedMessage m;
        in >> m;
        //On ne fait rien pour l'instant.
    }
    /**
      * Gère la reception d'un message de construction acceptée
      */
    void Client::handleBuildAccepted(QDataStream &in)
    {
        //On recupère le message
        Network::BuildAcceptedMessage m;
        in >> m;
        //On ne fait rien pour l'instant
    }
    /**
      * Gère la reception d'un message de travail accepté
      */
    void Client::handleWorkAccepted(QDataStream &in)
    {
        //On recupère le message
        Network::WorkAcceptedMessage m;
        in >> m;
        //On ne fait rien pour l'instant
    }
    /**
      * Gère la reception d'un message de nouveau tour
      */
    void Client::handleNewTurn(QDataStream &in)
    {
        //On recupère le message
        Network::NewTurnMessage m;
        in >> m;
        //On envoie le signal pour changer le numéro du tour
        emit turnNumberHasChanged(m.getTurn());
    }

    /**
      * Appelé quand le client doit se déconnecter
      */
    void Client::logout()
    {
        _isLogged = false;
        _isAdmin = true;
        _socket->close();
    }
}
