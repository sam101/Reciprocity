#include <Map/Building.h>
namespace Map
{
    /**
      * Constructeur
      */
    Building::Building(qint32 x, qint32 y, BuildingType type, qint32 level, qint32 lifePoints, qint32 maxLifePoints) :
    _type(type),
    _level(level),
    _lifePoints(lifePoints),
    _maxLifePoints(maxLifePoints),
    _x(x),
    _y(y)
    {

    }
    /**
      * Renvoie le type du batiment
      */
    BuildingType Building::getType() const
    {
        return _type;
    }
    /**
      * Renvoie le niveau du batiment
      */
    qint32 Building::getLevel() const
    {
        return _level;
    }
    /**
      * Renvoie les points de vie du batiment
      */
    qint32 Building::getLifePoints() const
    {
        return _lifePoints;
    }
    /**
      * Renvoie les points de vie maximums du batiment
      */
    qint32 Building::getMaxLifePoints() const
    {
        return _maxLifePoints;
    }
    /**
      * Renvoie la position X du batiment
      */
    qint32 Building::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y du batiment
      */
    qint32 Building::getY() const
    {
        return _y;
    }
}
