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
    _y(y)
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
}

