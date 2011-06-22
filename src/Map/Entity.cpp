#include <Map/Entity.h>
namespace Map
{
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
}
