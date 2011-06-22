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
                chunk->getTileAbs(j,i).setTile(Map::SEA,Map::Tile::BOAT_PASSABLE);
            }
        }
        /*n
          * On ajoute des iles de 1*1
          */
        int nbIsles = Random::next(0,Config::Config::CHUNK_SIZE);
        for (int i = 0; i < nbIsles; i++)
        {
            chunk->getTileAbs(Random::next(1,Config::Config::CHUNK_SIZE),Random::next(1,Config::Config::CHUNK_SIZE)).setAsLowLand();
        }
    }
}
