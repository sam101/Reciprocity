#include <Map/Tile.h>
namespace Map
{
    /**
      * Constructeur
      */
    Tile::Tile(qint32 x, qint32 y,qint32 flags, TileType type, qint32 output) :
    _flags(flags),
    _type(type),
    _output(output),
    _x(x),
    _y(y),
    _resources(Map::MAX,0)
    {

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
    qint32 Tile::getOutput() const
    {
        return _output;
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
    void Tile::setOutput(qint32 output)
    {
        _output = output;
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
    }
    /**
      * Définit la tile comme étant une montagne
      */
    void Tile::setAsMountain()
    {
        _type = MOUNTAIN;
        _flags=  PASSABLE;
    }
    /**
      * Définit la tile comme étant une foret
      */
    void Tile::setAsForest()
    {
        _type = FOREST;
        _flags=  PASSABLE;
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
    }
    /**
      * Définit la tile comme étant de la mer
      */
    void Tile::setAsBeach()
    {
        _type = BEACH;
        _flags = PASSABLE;
    }
    /**
      * Définit la tile comme étant un marais
      */
    void Tile::setAsSwamp()
    {
        _type = SWAMP;
        _flags = PASSABLE;
    }

    /**
      * Stocke une tile dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Tile &t)
    {
        out << Tile::TILE_MAGICNUMBER;
        out << Tile::TILE_VERSION;
        out << t._flags;
        out << (qint32)t._type;
        out << t._output;
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
        //On vérifie la version
        //TODO: Gérer toutes les versions de Tile après la 0.1
        qint32 version;
        in >> version;
        Q_ASSERT(version == Tile::TILE_VERSION);
        //On recupère les données
        in >> t._flags;
        in >> (qint32&)t._type;
        in >> t._output;
        in >> t._x;
        in >> t._y;
        in >> t._resources;
        return in;
    }
}

