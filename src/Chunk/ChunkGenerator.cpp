#include <Chunk/ChunkGenerator.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère une ile carrée
      */
    void ChunkGenerator::genSquareIsland(Chunk *chunk, int xStart, int xEnd, int yStart, int yEnd)
    {
        for (int i = xStart; i <= xEnd; i++)
        {
            for (int j = yStart; j <= yEnd; j++)
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
