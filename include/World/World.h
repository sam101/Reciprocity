#ifndef WORLD_WORLD_H
#define WORLD_WORLD_H
#include <QtCore/QVector>

#include <Chunk/Chunk.h>
namespace World
{
    /**
      * Gère le monde principal et sa génération, ainsi
      * que la présence des entités sur celui-ci.
      * @brief Gère le monde principal et sa génération.
      * @author Sam101
      */
    class World
    {
        protected:
            /**
              * Tableau des chunks
              */
            QVector<QVector<Chunk::Chunk> > _chunks;
    };
}
#endif //WORLD_WORLD_H
