#include <Chunk/LandChunkGenerator.h>
#include <Config/Config.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère un chunk de type "Land"
      * @brief Genère un chunk de type "Land"
      * @author Sam101
      */
    void LandChunkGenerator::generate(Chunk *chunk)
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
          * On genère un nombre important d'iles
          */
        int xStart, xEnd, yStart, yEnd;
        int nbIsles = Random::next(Config::Config::CHUNK_SIZE * 2,Config::Config::CHUNK_SIZE * 4);
        for (int i = 0; i < nbIsles; i++)
        {
            xStart = Random::next(5,Config::Config::CHUNK_SIZE - 5);
            xEnd = xStart + Random::next(0,5);
            yStart = Random::next(5,Config::Config::CHUNK_SIZE - 5);
            yEnd = yStart + Random::next(0,5);
            genSquareIsland(chunk,xStart,xEnd,yStart,yEnd);
        }
    }
}
