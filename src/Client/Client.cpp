#include <Client/Client.h>
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
}
