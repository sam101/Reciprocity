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
}
