#include <Server/MessageHandler.h>
#include <Network/AbstractMessage.h>
#include <Network/AttackMessage.h>
#include <Network/BeginGameMessage.h>
#include <Network/BuildMessage.h>
#include <Network/EndTurnMessage.h>
#include <Network/GetServerDataMessage.h>
#include <Network/KickPlayerMessage.h>
#include <Network/LoginMessage.h>
#include <Network/MessageOutMessage.h>
#include <Network/MoveUnitMessage.h>
#include <Network/RequestDataMessage.h>
#include <Network/WorkMessage.h>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QDataStream>
#include <QtCore/QDebug>
#include <QtNetwork/QHostAddress>
namespace Server
{
    /**
      * Constructeur
      */
    MessageHandler::MessageHandler(QMap<QTcpSocket*, Client*>& clients) :
    _game(NULL),
    _clients(clients)
    {

    }
    /**
      * Définit l'objet de jeu actuel
      */
    void MessageHandler::setGame(Game::Game *game)
    {
        _game = game;
    }
    /**
      * Appelé lors de la reception d'un message.
      * Detecte le type du message envoyé et
      * appelle la méthode correspondante au message reçu.
      */
    void MessageHandler::messageRecevied()
    {
        //On recupère la socket qui a envoyé le message
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        //On vérifie que la socket existe bien
        if (socket == 0)
        {
            qDebug() << tr("Attention, messageRecevied appelé par autre chose qu'une socket.");
            return;
        }
        //On déclare le datastream pour lire les données
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_4_5);
        while (_sizes[socket] < socket->bytesAvailable())
        {
            if (_sizes[socket] == 0)
            {
                //On vérifie qu'on a reçu la taille du message.
                if (socket->bytesAvailable() < (qint32)sizeof(qint32) )
                {
                    return;
                }
                //On recupère la taille.
                in >> _sizes[socket];
                //On vérifie que la taille est correcte
                if (_sizes[socket] < 0)
                {
                    qDebug() << "Taille de message incorrecte envoyée par" << socket->peerAddress().toString() ;
                    _sizes[socket] = 0;
                    emit errorMessage(socket);
                    return;
                }
            }
            //Si on a pas tout le message, on abandonne.
            if (socket->bytesAvailable() < _sizes[socket])
            {
                qDebug() << "Message complet non reçu:" << socket->bytesAvailable() << "/" << _sizes[socket];
                return;
            }
            //On recupère le type du message.
            qint32 type;
            in >> type;
            qDebug() << "Un message de taille" << _sizes[socket] << "a été reçu de " << socket->peerAddress().toString() << "de type" << type;
            //On remet à zéro la taille du message
            _sizes[socket] = 0;
            //On gère selon le type.
            switch (type)
            {
                //Si on a reçu un message de type "Login"
                case Network::LOGIN:
                    handleLogin(socket,in);
                break;
                //Si on a reçu un message de type "MessageOut"
                case Network::MESSAGE_OUT:
                    handleMessage(socket,in);
                break;
                //Si on a reçu une demande d'envoi des informations du serveur
                case Network::GET_SERVER_DATA:
                    handleGetServerData(socket,in);
                break;
                //Si on a reçu une demmande de début de partie
                case Network::BEGIN_GAME:
                    handleBeginGame(socket,in);
                break;
                //Demande d'envoi de données
                case Network::REQUEST_DATA:
                    handleRequestData(socket,in);
                break;
                //Kick d'un joueur.
                case Network::KICK_PLAYER:
                    handleKickPlayer(socket,in);
                break;
                //Déplacement d'une entité
                case Network::MOVEUNIT:
                    handleMoveUnit(socket,in);
                break;
                //Fin de tour
                case Network::ENDTURN:
                    handleEndTurn(socket,in);
                break;
                //Construction
                case Network::BUILD:
                    handleBuild(socket,in);
                break;
                //Travail des entités
                case Network::WORK:
                    handleWork(socket,in);
                break;
                //Attaque d'une entité sur une autre entité/batiment
                case Network::ATTACK:
                    handleAttack(socket,in);
                break;
                default:
                    //On lit les données pour les effacer
                    //socket->read(_sizes[socket]);
                    qDebug() << "Le message reçu est de type inconnu.";
            }
        }

    }
    /**
      * Gère le login d'un joueur
      */
    void MessageHandler::handleLogin(QTcpSocket *socket, QDataStream &in)
    {
        qDebug() << "Demande de login de la part de " << socket->peerAddress().toString();
        //On recupère le message
        Network::LoginMessage msg;
        in >> msg;
        qDebug() << socket->peerAddress().toString() << " veut se connecter en temps que " << msg.getLogin();
        /*
         * On vérifie que le joueur n'est pas déjà connecté et que
         * si c'est le cas son hash est bon.
         */
        Game::Player *player = _game->findPlayer(msg.getLogin());
        if (player != NULL && player->getHash() != msg.getHash())
        {
            //Si c'est le cas, on le signale et on termine
            emit loginAlreadyExists(socket,msg.getLogin());
            return;
        }
        /*
         * Si il existe déjà, on ne l'ajoute pas à la partie
         */
        if (player)
        {
            //On indique que le joueur est de retour.
            if (!_game->playerBack(msg.getLogin(),msg.getHash()))
            {
                qDebug() << "Erreur: Le joueur n'a pu être ramené à la vie";
                return;
            }
            qDebug() << "Le joueur " << msg.getLogin() << "vient de se reconnecter";
            //On met à jour les informations du client
            _clients[socket]->setPlayer(player);
            _clients[socket]->setLogin(msg.getLogin());
            _clients[socket]->setHash(msg.getHash());
            //On emet le signal
            emit loginSuccess(socket,player->getId(),player->isAdmin());
        }
        else
        {
            /*
              * Sinon, on ajoute le joueur à la partie
              */
           Game::Player *player = _game->addPlayer(msg.getLogin(),msg.getHash());
           _clients[socket]->setPlayer(player);
           _clients[socket]->setLogin(msg.getLogin());
           _clients[socket]->setHash(msg.getHash());
           qDebug() << "Login de" << socket->peerAddress().toString() << "En tant que" << msg.getLogin() << " réussi.";
           //On emet le signal
           emit loginSuccess(socket,player->getId(),player->isAdmin());
           emit sendServerDataToAll();
        }
        //Si la partie a commencé, on envoie le signal
        if (_game->hasBegun())
        {
            emit sendGameHasBegun(socket);
        }

    }
    /**
      * Gère la reception d'un message par un joueur
      */
    void MessageHandler::handleMessage(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::MessageOutMessage msg;
        in >> msg;
        //On affiche dans la console le contenu du message
        qDebug() <<  _clients[socket]->getLogin() << ":" << msg.getContents();
        //TODO: Antiflood.

        //On envoie le message à tout le monde
        emit sendMessage(msg.getDest(),msg.getContents(),_clients[socket]->getLogin());
    }
    /**
      * Gère la reception de la demande d'envoi des informations
      */
    void MessageHandler::handleGetServerData(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::GetServerDataMessage m;
        in >> m;

        emit sendServerData(socket);
    }
    /**
      * Gère la reception du message de demmande de début de partie
      */

    void MessageHandler::handleBeginGame(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::BeginGameMessage msg;
        in >> msg;
        //On affiche dans la console que le joueur à demandé le début de la partie
        qDebug() << _clients[socket]->getLogin() << "a demandé le début de la partie";
        //On emet le signal de début de partie
        //On emet le signal si la partie n'a pas déjà commencé
        if (_game->hasBegun())
        {
            emit errorHappened(socket,tr("La partie a déjà commencé"));
            return;
        }
        if (_clients[socket]->getPlayer() == NULL)
        {
            qDebug() << "Le joueur qui a demandé le début de la partie n'a pas d'objet joueur. Abandon.";
            return;
        }
        if (!_clients[socket]->getPlayer()->isAdmin())
        {
            qDebug() << "Attention: non-ad16902ministrateur demande le début de la partie";
            emit errorHappened(socket,tr("Accès refusé"));
            return;
        }
        //On met à jour l'objet Game
        _game->beginGame();
        //On envoie le signal
        emit sendGameHasBegunToAll();
    }
    /**
      * Gère la reception d'une demande d'envoi de données
      */
    void MessageHandler::handleRequestData(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::RequestDataMessage m;
        in >> m;
        //On envoie le signal comme quoi le joueur a demandé les données auqueles il a accès.
        emit sendPlayerData(socket);
    }
    /**
      * Gère la reception d'une demande de kick de joueur
      */
    void MessageHandler::handleKickPlayer(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::KickPlayerMessage m;
        in >> m;
        //On vérifie que le demandeur est bien administrateur
        if (_clients[socket]->getPlayer() == NULL)
        {
            return;
        }
        if (!_clients[socket]->getPlayer()->isAdmin())
        {
            emit errorHappened(socket,tr("Demande refusée"));
        }
        //On vérifie que le joueur existe
        if (_game->findPlayer(m.getLogin()) == NULL)
        {
            emit errorHappened(socket,tr("Joueur introuvable"));
            return;
        }
        //On envoie le signal comme quoi le joueur a été kické
        emit kickPlayer(m.getLogin());
        emit sendKickMessage(m.getLogin());
    }
    /**
      * Gère la reception d'une demande de déplacement
      */
    void MessageHandler::handleMoveUnit(QTcpSocket *socket, QDataStream &in)
    {
        qDebug() << "Demande de déplacement reçue de" << socket->peerAddress().toString();
        //On recupère le message
        Network::MoveUnitMessage m;
        in >> m;
        //On vérifie que l'envoyeur est bien loggué
        if (_clients[socket]->getPlayer() == NULL)
        {
            return;
        }
        Game::Player *player = _clients[socket]->getPlayer();
        //On vérifie que l'entité existe
        if (!player->getEntities().contains(m.getId()))
        {
            return;
        }
        //On vérifie que l'entité existe bien
        if (_game->getEntity(m.getId()) == NULL)
        {
            return;
        }
        //On vérifie que l'entité est pas déjà déplacée
        if (_game->getEntity(m.getId())->hasMoved())
        {
            qDebug() << "Refusée: l'entité a déjà bougé";
            return;
        }
        //On déplace l'entité
        _game->moveEntity(m.getId(),m.getX(),m.getY(),_clients[socket]->getPlayer()->getId());
        //On indique que l'entité a bougé
        emit entityMoved(socket,_game->getEntity(m.getId()));
    }
    /**
      * Gère la reception d'un message de fin de tour
      */
    void MessageHandler::handleEndTurn(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::EndTurnMessage m;
        in >> m;
        //On vérifie si le client est loggué
        if (_clients[socket]->getPlayer() == NULL)
        {
            return;
        }
        //On indique qu'il à fini son tour
        _clients[socket]->getPlayer()->setEndTurn();
        //On vérifie si tout les joueurs ont envoyé la fin du tour.
        QMapIterator<QTcpSocket*,Client*> it(_clients);
        bool everybodyEnd = true;
        while (it.hasNext())
        {
            Client *c = it.next().value();
            if (c->getPlayer() == NULL)
            {

            }
            else if (c->isOnline())
            {

            }
            else if (!c->getPlayer()->hasEndTurn())
            {
                everybodyEnd = false;
            }
        }
        //Si tout le monde a fini son tour, on fini le tour et on emet le signal
        if (everybodyEnd)
        {
            _game->newTurn();
            emit sendNewTurnToAll();
            emit sendPlayerDataToAll();
        }
    }
    /**
      * Gère la reception d'une demande de construction
      */
    void MessageHandler::handleBuild(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::BuildMessage m;
        in >> m;
        //On vérifie que le client est loggué et que l'entité existe.
        if (_clients[socket]->getPlayer() == NULL || _game->getEntity(m.getEntity()) == NULL)
        {
            return;
        }
        //On vérifie que l'entité est bien à lui.
        if (_clients[socket]->getPlayer()->getId() != _game->getEntity(m.getEntity())->getOwner())
        {
            return;
        }
        //On demande au jeu de construire le batiment.
        if (_game->build(m.getEntity(),m.getType()))
        {
            emit buildingBuilt(socket,m.getEntity());
        }
    }
    /**
      * Gère la reception d'une demande de travail
      */
    void MessageHandler::handleWork(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::WorkMessage m;
        in >> m;
        //On vérifie que le client est loggué.
        if (_clients[socket]->getPlayer() == NULL ||
        _game->getEntity(m.getEntity()) == NULL)
        {
            return;
        }
        //On vérifie que l'entité est bien à lui.
        if (_clients[socket]->getPlayer()->getId() != _game->getEntity(m.getEntity())->getOwner())
        {
            return;
        }
        //On demande au jeu de faire travailler l'entité
        if (_game->work(m.getEntity()))
        {
            emit workAccepted(socket,m.getEntity());
        }
    }
    /**
      * Gère la reception d'un message d'attaque
      */
    void MessageHandler::handleAttack(QTcpSocket *socket, QDataStream &in)
    {
        //On recupère le message
        Network::AttackMessage m;
        in >> m;
        //On vérifie que le client est loggué et que l'entité est bien à lui
        if (_clients[socket]->getPlayer() == NULL ||
        _game->getEntity(m.getEntityId()) == NULL ||
        _clients[socket]->getPlayer()->getId() != _game->getEntity(m.getEntityId())->getOwner())
        {
            return;
        }
        //On demande au jeu de faire l'attaque
        if (_game->attack(m.getEntityId(),m.getX(),m.getY()))
        {
            emit attackAccepted(socket,m.getEntityId(),m.getX(),m.getY());
        }
    }
}
