#include <Chunk/DesertLandChunkGenerator.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère un chunk
      * @param chunk Pointeur vers le chunk a générer (déjà alloué)
      */
    void DesertLandChunkGenerator::generate(Chunk *chunk)
    {
        /*
         * On genère de l'eau sur tout le chunk tout d'abord.
         */
        for (int i = 0; i  < Config::Config::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        /*
          * On genère une plage géante
          */
        int xDeb, yDeb, xFin, yFin;
        xDeb = Random::next(0,2);
        yDeb = Random::next(0,2);
        xFin = Random::next(Config::Config::CHUNK_SIZE - 2,Config::Config::CHUNK_SIZE);
        yFin = Random::next(Config::Config::CHUNK_SIZE - 2,Config::Config::CHUNK_SIZE);
        for (int i = xDeb; i <= xFin; i++)
        {
            for (int j = yDeb; j <= yFin; j++)
            {
                chunk->getTileAbs(i,j).setAsBeach();
            }
        }
    }

}
