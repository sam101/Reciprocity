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
    _hash(hash)
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
        qDebug() << "Un message a été reçu.";
    }
}
