#include <Map/Building.h>
namespace Map
{
    /**
      * Constructeur
      */
    Building::Building(qint32 x, qint32 y, BuildingType type, qint8 level, qint32 lifePoints, qint32 maxLifePoints, qint32 owner) :
    _type(type),
    _level(level),
    _finished(false),
    _lifePoints(lifePoints),
    _maxLifePoints(maxLifePoints),
    _x(x),
    _y(y),
    _owner(owner)
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
    qint8 Building::getLevel() const
    {
        return _level;
    }
    /**
      * Renvoie si le batiment est fini
      */
    bool Building::isFinished() const
    {
        return _finished;
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
      * Renvoie le propriétaire du batiment
      */
    qint32 Building::getOwner() const
    {
        return _owner;
    }
    /**
      * Change le type du batiment
      */
    void Building::setType(BuildingType type)
    {
        _type = type;
    }
    /**
      * Change le propriétaire du batiment
      */
    void Building::setOwner(qint32 owner)
    {
        _owner = owner;
    }
    /**
      * Avance la construction du batiment
      */
    void Building::advanceBuild(qint32 n)
    {
        _lifePoints += n;
        if (_lifePoints >= _maxLifePoints)
        {
            _lifePoints = _maxLifePoints;
            _finished = true;
        }

    }

    /**
      * Envoie un batiment dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Building &b)
    {
        out << b.BUILDING_MAGICNUMBER;
        out << (qint32)b._type;
        out << b._level;
        out << b._finished;
        out << b._lifePoints;
        out << b._maxLifePoints;
        out << b._x;
        out << b._y;
        out << b._owner;

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
        //On recupère les données
        in >> (qint32&)b._type;
        in >> b._level;
        in >> b._finished;
        in >> b._lifePoints;
        in >> b._maxLifePoints;
        in >> b._x;
        in >> b._y;
        in >> b._owner;

        return in;
    }
}
