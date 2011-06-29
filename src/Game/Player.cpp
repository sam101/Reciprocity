#include <Game/Player.h>
namespace Game
{
    /**
      * Constructeur
      */
    Player::Player(qint32 id, QString login, QString hash) :
    _id(id),
    _login(login),
    _hash(hash),
    _isOnline(true)
    {

    }
    /**
      * Renvoie l'id du joueur
      */
    qint32 Player::getId() const
    {
        return _id;
    }
    /**
      * Renvoie le login du joueur
      */
    QString Player::getLogin() const
    {
        return _login;
    }
    /**
      * Renvoie si le joueur est connecté
      */
    bool Player::isOnline() const
    {
        return _isOnline;
    }
    /**
      * Indique que le joueur est hors ligne
      */
    void Player::setOffline()
    {
        _isOnline = false;
    }
    /**
      * Indique que le joueur est en ligne
      */
    void Player::setOnline()
    {
        _isOnline = true;
    }
}
