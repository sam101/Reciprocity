#include <Map/Entity.h>
namespace Map
{
    /**
      * Constructeur
      */
    Entity::Entity(qint32 x, qint32 y, qint32 owner, qint32 lifePoints, qint32 will, qint32 age) :
    _id(-1),
    _x(x),
    _y(y),
    _lifePoints(lifePoints),
    _maxLifePoints(lifePoints),
    _owner(owner),
    _will(will),
    _hasMoved(false),
    _dead(false),
    _age(age),
    _resources(Map::MAX,0)
    {
        _abilities.resize(Map::LAST);
    }
    /**
      * Renvoie l'id de l'entité
      */
    qint32 Entity::getId() const
    {
        return _id;
    }
    /**
      * Renvoie la position X de l'entité
      */
    qint32 Entity::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y de l'entité
      */
    qint32 Entity::getY() const
    {
        return _y;
    }
    /**
      * Renvoie les points de vie de l'entité
      */
    qint32 Entity::getLifePoints() const
    {
        return _lifePoints;
    }
    /**
      * Renvoie les points de vie maximums de l'entité
      */
    qint32 Entity::getMaxLifePoints() const
    {
        return _maxLifePoints;
    }
    /**
      * Renvoie le propriétaire de l'entité
      */
    qint32 Entity::getOwner() const
    {
        return _owner;
    }
    /**
      * Renvoie la volonté de l'entité.
      */
    qint32 Entity::getWill() const
    {
        return _will;
    }
    /**
      * Renvoie si l'entité s'est déjà déplacée
      */
    bool Entity::hasMoved() const
    {
        return _hasMoved;
    }
    /**
      * Renvoie si l'entité est morte
      */
    bool Entity::isDead() const
    {
        return _dead;
    }
    /**
      * Renvoie l'age de l'entité.
      */
    qint32 Entity::getAge() const
    {
        return _age;
    }
    /**
      * Renvoie une ressource portée par l'entité
      */
    qint32 Entity::getResource(qint32 id)
    {
        return _resources[id];
    }

    /**
      * Change l'id de l'entité
      */
    void Entity::setId(qint32 id)
    {
        _id = id;
    }

    /**
      * Change la position de l'entité
      */
    void Entity::setXY(qint32 x, qint32 y)
    {
        _x = x;
        _y = y;
    }

    /**
      * Déplace l'entité
      */
    void Entity::move(qint32 x, qint32 y)
    {
        _x += x;
        _y += y;
    }
    /**
      * Change la volonté de l'entité.
      */
    void Entity::setWill(qint32 will)
    {
        _will = will;
    }
    /**
      * Ajoute à la volonté de l'entité.
      */
    void Entity::addWill(qint32 will)
    {
        _will += will;
    }
    /**
      * Enlève de la volonté à l'entité
      */
    void Entity::delWill(qint32 will)
    {
        _will -= will;
        _will = _will < 0 ? 0 : _will;
    }

    /**
      * Tue l'entité
      */
    void Entity::kill()
    {
        _dead = true;
        _lifePoints = 0;
    }
    /**
      * Ajoute un à l'age de l'entité.
      */
    void Entity::age()
    {
        _age++;
    }
    /**
      * Indique que l'unité a été déplacée
      */
    void Entity::setHasMoved(bool hasMoved)
    {
        _hasMoved = hasMoved;
    }
    /**
      * Remet à zéro le fait que l'unité a été déplacée
      */
    void Entity::resetMove()
    {
        _hasMoved =  false;
    }
    /**
      * Ajoute une ressource à l'entité
      */
    void Entity::addResource(qint32 id, qint32 value)
    {
        _resources[id] += value;
    }
    /**
      * Enlève une ressource à l'entité
      */
    void Entity::delRessource(qint32 id, qint32 value)
    {
        _resources[id] -= value;
    }

    /**
      * Stocke une entité dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Entity &e)
    {
        out << Entity::ENTITY_MAGICNUMBER;
        out << Entity::ENTITY_VERSION;
        out << e._x;
        out << e._y;
        out << e._id;
        out << e._lifePoints;
        out << e._maxLifePoints;
        out << e._owner;
        out << e._will;
        out << e._hasMoved;
        out << e._dead;
        out << e._age;
        out << e._abilities;
        out << e._resources;

        return out;
    }
    /**
      * Recupère une entité d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, Entity &e)
    {
        //On vérifie le magicNumber et la version
        qint32 magicNumber;
        in >> magicNumber;
        Q_ASSERT(magicNumber == Entity::ENTITY_MAGICNUMBER);
        qint32 version;
        in >> version;
        Q_ASSERT(version == Entity::ENTITY_VERSION);
        //On recupère les données
        in >> e._x;
        in >> e._y;
        in >> e._id;
        in >> e._lifePoints;
        in >> e._maxLifePoints;
        in >> e._owner;
        in >> e._will;
        in >> e._hasMoved;
        in >> e._dead;
        in >> e._age;
        in >> e._abilities;
        in >> e._resources;

        return in;
    }
}
