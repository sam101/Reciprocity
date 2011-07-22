#include <Server/MessageHandler.h>
#include <Network/AbstractMessage.h>
#include <Network/LoginMessage.h>
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
        qDebug() << "Un message a été reçu de " << socket->peerAddress();

        //On vérifie que la socket existe bien
        if (socket == 0)
        {
            qDebug() << tr("Attention, messageRecevied appelé par autre chose qu'une socket.");
            return;
        }
        //On déclare le datastream pour lire les données
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_4_5);
        if (_sizes[socket] == 0)
        {
            //On vérifie qu'on a reçu la taille du message.
            if (socket->bytesAvailable() < (qint32)sizeof(qint32) )
            {
                return;
            }
            //On vérifie qu'on à bien tout le message.
            in >> _sizes[socket];
            //On vérifie que la taille est correcte
            if (_sizes[socket] < 0)
            {
                qDebug() << "Erreur: taille reçue incorrecte";
                emit errorMessage(socket);
                return;
            }
            else
            {
                qDebug() << "Taille du message:" << _sizes[socket];
            }
        }
        //Si on a pas tout le message, on abandonne.
        if (socket->bytesAvailable() < _sizes[socket])
        {
            return;
        }
        //On recupère le type du message.
        qint32 type;
        in >> type;
        //On gère selon le type.
        switch (type)
        {
            //Si on a reçu un message de type vide
            case Network::NONE:
                //On ne fait rien.
            break;
            //Si on a reçu un message de type "Login"
            case Network::LOGIN:
                handleLogin(socket,in);
            break;
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
        if (_game->findPlayer(msg.getLogin()) && _game->findPlayer(msg.getLogin())->getHash() != msg.getHash())
        {
            //Si c'est le cas, on le signale et on termine
            emit loginAlreadyExists(socket,msg.getLogin());
            return;
        }
        /*
          * Sinon, on ajoute le joueur à la partie
          */
       Game::Player *player = _game->addPlayer(msg.getLogin(),msg.getHash());
       qDebug() << "Création player OK";
       _clients[socket]->setPlayer(player);
       qDebug() << "SetPlayer OK";
       //On emet le signal
       emit loginSuccess(socket,player->getId());

    }
}
