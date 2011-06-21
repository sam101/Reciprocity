#ifndef CHUNK_LANDCHUNKGENERATOR_H
#define CHUNK_LANDCHUNKGENERATOR_H
#include <Chunk/ChunkGenerator.h>
namespace Chunk
{
    /**
      * Genère un chunk de type "Land"
      * @brief Genère un chunk de type "Land"
      * @author Sam101
      */
    class LandChunkGenerator : public ChunkGenerator
    {
        public:
            void generate(Chunk *chunk);
    };
}
#endif //CHUNK_LANDCHUNKGENERATOR_H
