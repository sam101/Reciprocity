#include <Server/Client.h>
namespace Server
{
    /**
      * Constructeur
      */
    Client::Client(QTcpSocket *socket)  :
    _socket(socket)
    {

    }
    /**
      * Renvoie le socket du client
      */
    QTcpSocket* Client::getSocket()
    {
        return _socket;
    }
    /**
      * Renvoie le socket du client.
      * Surchargé constant
      */
    const QTcpSocket* Client::getSocket() const
    {
        return _socket;
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
      * Change le login du client
      */
    void Client::setLogin(QString login)
    {
        _login = login;
    }
    /**
      * Change le hash du client
      */
    void Client::setHash(QString hash)
    {
        _hash = hash;
    }
}
