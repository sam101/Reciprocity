#include <Chunk/LandChunkGenerator.h>
#include <Config/Config.h>
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
                chunk->getTileAbs(j,i).setTile(Map::LOWLAND,Map::Tile::PASSABLE | Map::Tile::FARMING_CAPABLE);
            }
        }
        /*
         * On met de l'eau sur les bordures.
         */
        for (int i = 0; i < Config::Config::CHUNK_SIZE; i++)
        {
            chunk->getTileAbs(i,0).setTile(Map::SEA,Map::Tile::BOAT_PASSABLE);
            chunk->getTileAbs(0,i).setTile(Map::SEA,Map::Tile::BOAT_PASSABLE);
            chunk->getTileAbs(Config::Config::CHUNK_SIZE - 1,i).setTile(Map::SEA,Map::Tile::BOAT_PASSABLE);
            chunk->getTileAbs(i,Config::Config::CHUNK_SIZE - 1).setTile(Map::SEA,Map::Tile::BOAT_PASSABLE);
        }
    }
}
