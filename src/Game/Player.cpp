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
    _admin(false),
    _endTurn(false)
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
      * Renvoie si le joueur a fini son tour
      */
    bool Player::hasEndTurn() const
    {
        return _endTurn;
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
      * Change le fait que le joueur aie fini son tour ou non
      */
    void Player::setEndTurn(bool endTurn)
    {
        _endTurn = endTurn;
    }
    /**
      * Remet à zéro le fait que le joueur aie fini son tour
      */
    void Player::resetEndTurn()
    {
        _endTurn = false;
    }

    /**
      * Ajoute une entité au joueur
      */
    void Player::addEntity(qint32 id)
    {
        if (!_entities.contains(id))
        {
            _entities.append(id);
        }
    }
    /**
      * Envoie le Player dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Player &p)
    {
        out << p.MAGICNUMBER_PLAYER;
        out << p._id;
        out << p._login;
        out << p._hash;
        out << p._lastTime;
        out << p._isOnline;
        out << p._admin;
        out << p._endTurn;
        out << p._entities;

        return out;
    }
    /**
      * Recupère le Player d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, Player &p)
    {
        qint32 magicNumber;
        in >> magicNumber;
        in >> p._id;
        in >> p._login;
        in >> p._hash;
        in >> p._lastTime;
        in >> p._isOnline;
        in >> p._admin;
        in >> p._endTurn;
        in >> p._entities;

        return in;
    }
}
