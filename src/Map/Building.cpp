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
    /**
      * Envoie un batiment dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Building &b)
    {
        out << b.BUILDING_MAGICNUMBER;
        out << b.BUILDING_VERSION;
        out << (qint32)b._type;
        out << b._level;
        out << b._lifePoints;
        out << b._maxLifePoints;
        out << b._x;
        out << b._y;

        return out;
    }
    /**
      * Recupère un batiment d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, Building &b)
    {
        //On vérifie le magicNumber et la version
        qint32 magicNumber;
        in >> magicNumber;
        Q_ASSERT(magicNumber == Building::BUILDING_MAGICNUMBER);
        qint32 version;
        in >> version;
        Q_ASSERT(version == Building::BUILDING_VERSION);
        //On recupère les données
        in >> (qint32&)b._type;
        in >> b._level;
        in >> b._lifePoints;
        in >> b._maxLifePoints;
        in >> b._x;
        in >> b._y;

        return in;
    }
}
