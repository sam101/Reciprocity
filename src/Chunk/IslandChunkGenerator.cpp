#include <Chunk/IslandChunkGenerator.h>
#include <Tools/Random.h>
#include <QtCore/QDebug>
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
        int xDebut = Random::next(5,Config::Config::CHUNK_SIZE - 5);
        int xFin = xDebut + Random::next(2,Config::Config::CHUNK_SIZE - xDebut - 1);
        int yDebut = Random::next(5,Config::Config::CHUNK_SIZE - 5);
        int yFin = yDebut + Random::next(2,Config::Config::CHUNK_SIZE - yDebut - 1);
        qDebug() << xDebut << xFin << yDebut << yFin;
        for (int i = xDebut; i <= xFin; i++)
        {
            for (int j = yDebut; j <= yFin; j++)
            {
                chunk->getTileAbs(i,j).setAsLowLand();
            }
        }


    }
}
