#include <Chunk/Chunk.h>
#include <Config/Config.h>
namespace Chunk
{
    /**
      * Constructeur
      */
    Chunk::Chunk(qint32 x, qint32 y, ChunkType type) :
    _x(x),
    _y(y),
    _type(type)
    {
        /*
         * On construit le tableau de tiles
         */
        _tiles.resize(Config::Config::CHUNK_SIZE);
        for (int i = 0; i < _tiles.size(); i++)
        {
            _tiles[i].resize(Config::Config::CHUNK_SIZE);
        }
        /*
         * On construit le tableau des id d'entités
         */
        _entities.resize(Config::Config::CHUNK_SIZE);
        for (int i = 0; i < _entities.size(); i++)
        {
            _entities.resize(Config::Config::CHUNK_SIZE);

            for (int j = 0; j < _entities[i].size(); i++)
            {
                _entities[i][j] = -1;
            }
        }
    }
    /**
      * Renvoie le type du chunk
      */
    ChunkType Chunk::getType() const
    {
        return _type;
    }
    /**
      * Renvoie la position x du chunk
      */
    qint32 Chunk::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position y du chunk
      */
    qint32 Chunk::getY() const
    {
        return _y;
    }
    /**
      * Renvoie une tile du chunk
      */
    Map::Tile& Chunk::getTile(qint32 x, qint32 y)
    {
        return _tiles[y - _y][x - _x];
    }
    /**
      * Renvoie une tile du chunk.
      * surchargé constant.
      */
    const Map::Tile& Chunk::getTile(qint32 x, qint32 y) const
    {
        return _tiles[y - _y][x - _x];
    }
}
