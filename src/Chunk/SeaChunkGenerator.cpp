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
        int xDebut, xFin, yDebut, yFin;
        int nbIsles = Random::next(0,Config::Config::CHUNK_SIZE / 4);
        for (int i = 0; i < nbIsles; i++)
        {
            xDebut = Random::next(4,Config::Config::CHUNK_SIZE - 4);
            xFin = xDebut + Random::next(0,4);
            yDebut = Random::next(4,Config::Config::CHUNK_SIZE - 4);
            yFin = xDebut + Random::next(0,4);
            chunk->getTileAbs(Random::next(1,Config::Config::CHUNK_SIZE),Random::next(1,Config::Config::CHUNK_SIZE)).setAsLowLand();
            for (int i = xDebut; i <= xFin; i++)
            {
                for (int j = yDebut; j <= yFin; j++)
                {
                    if (Random::next(0,10) == 5)
                    {
                        chunk->getTileAbs(i,j).setAsForest();
                    }
                    else if (Random::next(0,15) == 5)
                    {
                        chunk->getTileAbs(i,j).setAsMountain();
                    }
                    else
                    {
                        chunk->getTileAbs(i,j).setAsLowLand();
                    }
                }
            }

        }
    }
}
