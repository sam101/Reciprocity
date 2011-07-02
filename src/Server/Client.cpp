#include <Server/Client.h>
namespace Server
{
    /**
      * Constructeur
      */
    Client::Client(QTcpSocket *socket)  :
    _socket(socket),
    _isOnline(true),
    _player(NULL)
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
      * Renvoie le pointeur vers le joueur du client
      */
    Game::Player* Client::getPlayer()
    {
        return _player;
    }
    /**
      * Renvoie le pointeur vers le joueur du client
      * surchargé constant
      */
    const Game::Player* Client::getPlayer() const
    {
        return _player;
    }
    /**
      * Renvoie si le client est en ligne
      */
    bool Client::isOnline() const
    {
        return _isOnline;
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
    /**
      * Indique que le client est offline
      */
    void Client::setOffline()
    {
        _isOnline = false;
    }
    /**
      * Change le joueur utilisé par le client
      */
    void Client::setPlayer(Game::Player *player)
    {
        _player = player;
    }
}
