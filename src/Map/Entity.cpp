#include <Map/Entity.h>
namespace Map
{
    /**
      * Constructeur
      */
    Entity::Entity(qint32 x, qint32 y, qint32 owner, qint32 lifePoints, qint32 will, qint32 age) :
    _x(x),
    _y(y),
    _lifePoints(lifePoints),
    _maxLifePoints(lifePoints),
    _owner(owner),
    _will(will),
    _age(age)
    {
        _abilities.resize(Map::LAST);
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
}
