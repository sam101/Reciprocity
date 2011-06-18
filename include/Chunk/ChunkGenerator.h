#ifndef CHUNK_CHUNKGENERATOR_H
#define CHUNK_CHUNKGENERATOR_H
#include <Chunk/Chunk.h>
namespace Chunk
{
    /**
      * Classe abstraite de base pour les classes générant un
      * chunk
      * @brief Classe abstraite pour la génération de chunk
      * @author Sam101
      */
    class ChunkGenerator
    {
        public:
            virtual void generate(Chunk::Chunk *chunk) = 0;
    };
}
#endif //CHUNK_CHUNKGENERATOR_H
