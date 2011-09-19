#include <Chunk/IslandChunkGenerator.h>
#include <Config/BaseConfig.h>
#include <Tools/Random.h>
#include <QtCore/QDebug>
using namespace Config;
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
        for (int i = 0; i < BaseConfig::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < BaseConfig::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        /*
          * On ajoute des iles
          */
        int xStart, xEnd, yStart, yEnd;
        int nbIsles = Random::next(BaseConfig::CHUNK_SIZE,BaseConfig::CHUNK_SIZE * 3);
        for (int i = 0; i < nbIsles; i++)
        {
            xStart = Random::next(4,BaseConfig::CHUNK_SIZE - 4);
            xEnd = xStart + Random::next(0,4);
            yStart = Random::next(4,BaseConfig::CHUNK_SIZE - 4);
            yEnd = yStart + Random::next(0,4);
            genSquareIsland(chunk,xStart,xEnd,yStart,yEnd);
        }


    }
}
