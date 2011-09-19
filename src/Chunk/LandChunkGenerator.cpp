#include <Chunk/LandChunkGenerator.h>
#include <Config/BaseConfig.h>
#include <Config/Config.h>
#include <Tools/Random.h>
using namespace Tools;
using namespace Config;
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
        for (int i = 0; i  < BaseConfig::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < BaseConfig::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        /*
          * On genère un nombre important d'iles
          */
        const int NB = 5;
        int xStart, xEnd, yStart, yEnd;
        int nbIsles = Random::next(BaseConfig::CHUNK_SIZE * 3,BaseConfig::CHUNK_SIZE * 4);
        for (int i = 0; i < nbIsles; i++)
        {
            xStart = Random::next(0,BaseConfig::CHUNK_SIZE);
            xEnd = xStart + Random::next(0,NB);
            xEnd = xEnd >= BaseConfig::CHUNK_SIZE ? BaseConfig::CHUNK_SIZE - 1 : xEnd;
            yStart = Random::next(5,BaseConfig::CHUNK_SIZE);
            yEnd = yStart + Random::next(0,NB );
            yEnd = yEnd >= BaseConfig::CHUNK_SIZE ? BaseConfig::CHUNK_SIZE - 1 : yEnd;
            genSquareIsland(chunk,xStart,xEnd,yStart,yEnd);
        }
        //On rajoute des marais au milieu.
        int nb = Random::next(0,10);
        int x, y;
        for (int i = 0; i < nb; i++)
        {
            x = Random::next(1,BaseConfig::CHUNK_SIZE - 1);
            y = Random::next(1,BaseConfig::CHUNK_SIZE - 1);
            chunk->getTileAbs(x,y).setAsSwamp();
        }
        //On ajoute un volcan
        if (Random::next(0,10) == 10)
        {
            for (int i = 0; i < 42; i++)
            {
                int x = Random::next(10,BaseConfig::CHUNK_SIZE - 10);
                int y = Random::next(10,BaseConfig::CHUNK_SIZE - 10);
                chunk->getTileAbs(x,y).setAsVolcano();
            }
        }
    }
}
