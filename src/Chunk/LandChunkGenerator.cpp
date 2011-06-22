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
         * On genère des plaines sur tout le chunk tout d'abord.
         */
        for (int i = 0; i  < Config::Config::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsLowLand();
            }
        }

        /*
         * On ajoute des montagnes parsemées
         */
        for (int i = 1; i < Config::Config::CHUNK_SIZE - 1; i++)
        {
            for (int j = 1; j < Config::Config::CHUNK_SIZE - 1; j++)
            {
                if (Random::next(0,20) == 5)
                {
                    chunk->getTileAbs(j,i).setAsMountain();
                }
            }
        }
        /*
          * On ajoute des forêts parsemées
          */
        for (int i = 1; i < Config::Config::CHUNK_SIZE - 1; i++)
        {
            for (int j = 1; j < Config::Config::CHUNK_SIZE - 1; j++)
            {
                if (Random::next(0,10) == 5)
                {
                    chunk->getTileAbs(j,i).setAsForest();
                }
            }
        }
    }
}
