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
}
