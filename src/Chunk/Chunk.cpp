#include <Chunk/Chunk.h>
#include <Config/Config.h>
namespace Chunk
{
    /**
      * Constructeur
      */
    Chunk::Chunk(ChunkType type) :
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
}
