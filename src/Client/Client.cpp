#include <Client/Client.h>
#include <Config/Config.h>
#include <Network/LoginMessage.h>
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
                    emit loginSuccess();
                break;
                case Network::LOGIN_FAILED:
                    emit loginFailed();
                break;
            }
        }
    }
    /**
      * Appelé quand le client doit se déconnecter
      */
    void Client::logout()
    {
        _isLogged = false;
        _socket->close();
    }
}
