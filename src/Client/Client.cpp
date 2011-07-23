#include <Client/Client.h>
#include <Config/Config.h>
#include <Network/LoginMessage.h>
#include <Network/LoginSuccessMessage.h>
#include <Network/MessageInMessage.h>
#include <Network/MessageOutMessage.h>
#include <QtCore/QDataStream>
#include <QtCore/QDebug>
namespace Client
{
    /**
      * Constructeur
      */
    Client::Client(QTcpSocket *socket, QString login, QString hash) :
    _socket(socket),
    _isLogged(false),
    _isAdmin(false),
     _id(-1),
    _login(login),
    _hash(hash),
    _messageSize(0)
    {
        //On connecte les signaux du socket
        connect(_socket,SIGNAL(readyRead()),this,SLOT(messageRecevied()));
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
      * Envoie un message de login
      */
    void Client::sendLoginMessage()
    {
        qDebug() << "Appel de Client::sendLoginMessage";
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
      * Envoie un message de début de partie
      */
    void Client::sendBeginGame()
    {
        //TODO
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
            //On vérifie que la tailel est correcte
            if (_messageSize < 0)
            {
                qDebug() << "Erreur: Message incorrect reçu";
                _messageSize = 0;

                emit incorrectMessage();

                return;
            }
            if (_socket->bytesAvailable() < _messageSize)
            {
                return;
            }
            _messageSize = 0;
            qDebug() << "Message reçu du serveur";
            //On recupère le type du message
            qint32 type;
            in >> type;
            //On gère selon le type
            switch (type)
            {
                case Network::NONE:
                //On ne fait rien
                break;
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
        qDebug() << m.getSender() << ":" << m.getContents();
        //On emet le signal comme quoi on a reçu un message.
        emit messageRecevied(m.getSender(),m.getContents());
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
