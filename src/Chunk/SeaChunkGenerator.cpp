#include <Chunk/SeaChunkGenerator.h>
#include <Config/Config.h>
namespace Chunk
{
    /**
      * Genère un chunk de type "Mer".
      * Ces chunk contiennent uniquement de l'eau et quelques iles
      */
    void SeaChunkGenerator::generate(Chunk *chunk)
    {
        /**
          * On remplit le chunk de mer
          */
        for (int i = 0; i < Config::Config::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTile(j,i).setTile(Map::SEA,BOAT_PASSABLE);
            }
        }
    }
}
