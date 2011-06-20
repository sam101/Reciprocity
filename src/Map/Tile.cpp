#include <Map/Tile.h>
namespace Map
{
    /**
      * Constructeur
      */
    Tile::Tile(qint32 x, qint32 y,qint32 flags, TileType type, qint32 output) :
    _flags(flags),
    _type(type),
    _output(output)
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
}

