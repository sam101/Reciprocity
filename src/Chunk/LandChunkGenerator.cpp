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
        const int NB = 5;
        int xStart, xEnd, yStart, yEnd;
        int nbIsles = Random::next(Config::Config::CHUNK_SIZE * 3,Config::Config::CHUNK_SIZE * 4);
        for (int i = 0; i < nbIsles; i++)
        {
            xStart = Random::next(0,Config::Config::CHUNK_SIZE);
            xEnd = xStart + Random::next(0,NB);
            xEnd = xEnd >= Config::Config::CHUNK_SIZE ? Config::Config::CHUNK_SIZE - 1 : xEnd;
            yStart = Random::next(5,Config::Config::CHUNK_SIZE);
            yEnd = yStart + Random::next(0,NB );
            yEnd = yEnd >= Config::Config::CHUNK_SIZE ? Config::Config::CHUNK_SIZE - 1 : yEnd;
            genSquareIsland(chunk,xStart,xEnd,yStart,yEnd);
        }
        //On rajoute des marais au milieu.
        int nb = Random::next(0,10);
        int x, y;
        for (int i = 0; i < nb; i++)
        {
            x = Random::next(1,Config::Config::CHUNK_SIZE - 1);
            y = Random::next(1,Config::Config::CHUNK_SIZE - 1);
            chunk->getTileAbs(x,y).setAsSwamp();
        }
    }
}
