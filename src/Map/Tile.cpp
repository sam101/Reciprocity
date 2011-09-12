#include <Map/Tile.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Map
{
    /**
      * Constructeur
      */
    Tile::Tile(qint32 x, qint32 y,qint32 flags, TileType type, qint32 output) :
    _flags(flags),
    _type(type),
    _output(output),
    _maxOutput(output),
    _x(x),
    _y(y),
    _resources(Map::MAX,0)
    {

    }
    /**
      * Renvoie la position X de la tile
      */
    qint32 Tile::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y de la tile
      */
    qint32 Tile::getY() const
    {
        return _y;
    }
    /**
      * Renvoie les capacités de la tile
      */
    qint32 Tile::getFlags() const
    {
        return _flags;
    }
    /**
      * Renvoie le type de la tile.
      */
    TileType Tile::getType() const
    {
        return _type;
    }
    /**
      * Renvoie la productivité de la tile.
      */
    qint16 Tile::getOutput() const
    {
        return _output;
    }
    /**
      * Renvoie la productivité maximale de la tile
      */
    qint16 Tile::getMaxOutput() const
    {
        return _maxOutput;
    }
    /**
      * Renvoie une ressource de la tile
      */
    qint32 Tile::getResource(qint32 id)
    {
        //TODO: Vérification.
        return _resources[id];
    }

    /**
      * Définit les paramètres de la tile
      */
    void Tile::setTile(TileType type, qint32 flags)
    {
        _type = type;
        if (flags != 0)
        {
            _flags = flags;
        }
    }
    /**
      * Définit le rendement de la tile.
      */
    void Tile::setOutput(qint16 output)
    {
        _output = output;
    }
    /**
      * Diminue la productivité de la tile
      */
    void Tile::delOutput(qint16 output)
    {
        _output -= output;
        _output = _output < 0 ? 0 : _output;
    }
    /**
      * Remonte la productivité de la tile.
      * Ne peut pas monter au dessus de la productivité maximale
      */
    void Tile::restoreOutput(qint16 output)
    {
        _output += output;
        _output = _output > _maxOutput ? _maxOutput : _output;
    }

    /**
      * Change la valeur d'une ressource
      */
    void Tile::setResource(qint32 id, qint32 value)
    {
        _resources[id] = value;
    }
    /**
      * Ajoute une ressource à la tile
      */
    void Tile::addResource(qint32 id, qint32 value)
    {
        _resources[id] = value;
    }
    /**
      * Enlève une ressource à la tile
      */
    void Tile::delResource(qint32 id, qint32 value)
    {
        _resources[id] = value;
    }
    /**
      * Définit la tile comme étant une plaine
      */
    void Tile::setAsLowLand()
    {
        _type = LOWLAND;
        _flags = PASSABLE | FARMING_CAPABLE;
        _output = Random::next(50,100) + Random::next(0,2) * 25;
    }
    /**
      * Définit la tile comme étant une montagne
      */
    void Tile::setAsMountain()
    {
        _type = MOUNTAIN;
        _flags=  PASSABLE;
        _output = Random::next(15,110) + Random::next(0,3) * 25;
    }
    /**
      * Définit la tile comme étant une foret
      */
    void Tile::setAsForest()
    {
        _type = FOREST;
        _flags=  PASSABLE;
        _output = Random::next(20,100) + Random::next(0,1) * 50 + Random::next(0,2) * 25;
    }
    /**
      * Définit la tile comme étant un lac
      */
    void Tile::setAsLake()
    {
        _type = LAKE;
        _flags = BOAT_PASSABLE;
    }
    /**
      * Définit la tile comme étant une rivière
      */
    void Tile::setAsRiver()
    {
        _type = RIVER;
        _flags = BOAT_PASSABLE | PASSABLE;
    }
    /**
      * Définit la tile comme étant de la mer
      */
    void Tile::setAsSea()
    {
        _type = SEA;
        _flags = BOAT_PASSABLE;
        _output = Random::next(75,100);
    }
    /**
      * Définit la tile comme étant de la mer
      */
    void Tile::setAsBeach()
    {
        _type = BEACH;
        _flags = PASSABLE;
        _output = Random::next(75,125);
    }
    /**
      * Définit la tile comme étant un marais
      */
    void Tile::setAsSwamp()
    {
        _type = SWAMP;
        _flags = PASSABLE;
        _output = Random::next(50,200);
    }
    /**
      * Définit la tile comme étant un volcan
      */
    void Tile::setAsVolcano()
    {
        _type = VOLCANO;
        _flags = 0;
    }

    /**
      * Stocke une tile dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Tile &t)
    {
        out << Tile::TILE_MAGICNUMBER;
        out << t._flags;
        out << (qint32)t._type;
        out << t._output;
        out << t._maxOutput;
        out << t._x;
        out << t._y;
        out << t._resources;

        return out;
    }
    /**
      * Recupère une tile d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, Tile &t)
    {
        //On vérifie le magic number
        qint32 magicNumber;
        in >> magicNumber;
        Q_ASSERT(magicNumber == Tile::TILE_MAGICNUMBER);
        //On recupère les données
        in >> t._flags;
        in >> (qint32&)t._type;
        in >> t._output;
        in >> t._maxOutput;
        in >> t._x;
        in >> t._y;
        in >> t._resources;
        return in;
    }
}

