#include <Chunk/IslandChunkGenerator.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère un chunk "island".
      * @param chunk Pointeur vers le chunk a générer (déjà alloué)
      */
    void IslandChunkGenerator::generate(Chunk *chunk)
    {
        /*
          * On remplit le chunk de mer
          */
        for (int i = 0; i < Config::Config::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        /*
         * On détermine les coordonnées x,y de début et de fin
         * de l'ile
         */

    }
}
