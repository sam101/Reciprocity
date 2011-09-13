#include <Chunk/SeaChunkGenerator.h>
#include <Config/Config.h>
#include <Tools/Random.h>
#include <QtCore/QDebug>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère un chunk de type "Mer".
      * Ces chunk contiennent uniquement de l'eau et quelques iles
      */
    void SeaChunkGenerator::generate(Chunk *chunk)
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
          * On ajoute des iles.
          */
        int xStart, xEnd, yStart, yEnd;
        int nbIsles = Random::next(0,Config::Config::CHUNK_SIZE / 2);
        for (int i = 0; i < nbIsles; i++)
        {
            xStart = Random::next(4,Config::Config::CHUNK_SIZE - 4);
            xEnd = xStart + Random::next(0,4);
            yStart = Random::next(4,Config::Config::CHUNK_SIZE - 4);
            yEnd = yStart + Random::next(0,4);
            genSquareIsland(chunk,xStart,xEnd,yStart,yEnd);


        }
    }
}
