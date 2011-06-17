#include <Map/Tile.h>
namespace Map
{
    /**
      * Constructeur
      */
    Tile::Tile(qint32 flags, TileType type, qint32 output, qint32 x, qint32 y) :
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
      * Renvoie la position X de la tile dans le tileset.
      */
    qint32 Tile::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y de la tile dans le tileset.
      */
    qint32 Tile::getY() const
    {
        return _y;
    }
}
