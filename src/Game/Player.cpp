#include <Game/Player.h>
#include <QtCore/QDateTime>
namespace Game
{
    /**
      * Constructeur
      */
    Player::Player(qint32 id, QString login, QString hash) :
    _id(id),
    _login(login),
    _hash(hash),
    _isOnline(true),
    _admin(false)
    {
        _lastTime = QDateTime::currentMSecsSinceEpoch();
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
      * Renvoie le hash du joueur
      */
    QString Player::getHash() const
    {
        return _hash;
    }
    /**
      * Renvoie la date a laquelle le joueur a envoyé un message
      */
    qint64 Player::getLastTime() const
    {
        return _lastTime;
    }
    /**
      * Renvoie les entités du joueur
      */
    QList<qint32>& Player::getEntities()
    {
        return _entities;
    }
    /**
      * Renvoie les entités du joueur.
      * Surchargé constant
      */
    const QList<qint32>& Player::getEntities() const
    {
        return _entities;
    }
    /**
      * Renvoie si le joueur est connecté
      */
    bool Player::isOnline() const
    {
        return _isOnline;
    }
    /**
      * Renvoie si le joueur est administrateur
      */
    bool Player::isAdmin() const
    {
        return _admin;
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
    /**
      * Change les droits d'administration du joueur
      */
    void Player::setAdmin(bool admin)
    {
        _admin = admin;
    }
    /**
      * Met à jour le lastTime du Joueur.
      */
    void Player::resetLastTime()
    {
        _lastTime = QDateTime::currentMSecsSinceEpoch();
    }
    /**
      * Ajoute une entité au joueur
      */
    void Player::addEntity(const Map::Entity &entity)
    {
        if (!_entities.contains(entity.getId()))
        {
            _entities.append(entity.getId());
        }
    }

}
