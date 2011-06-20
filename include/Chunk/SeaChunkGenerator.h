#ifndef CHUNK_SEACHUNKGENERATOR_H
#define CHUNK_SEACHUNKGENERATOR_H
#include <Chunk/ChunkGenerator.h>
namespace Chunk
{
    class SeaChunkGenerator : public ChunkGenerator
    {
        public:
            /**
              * Genère un chunk de type "Mer".
              * Ces chunk contiennent uniquement de l'eau et quelques iles
              */
            virtual void generate(Chunk *chunk);

    };
}
#endif //CHUNK_SEACHUNKGENERATOR_H
