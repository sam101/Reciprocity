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
              * Tableau des chunks en haut à gauche
              */
            QVector<QVector<Chunk::Chunk*> > _chunkTL;
            /**
              * Tableau des chunks en haut à droite
              */
                QVector<QVector<Chunk::Chunk*> > _chunkTR;
            /**
              * Tableau des chunks en bas à gauche
              */
            QVector<QVector<Chunk::Chunk*> > _chunkBL;
            /**
              * Tableau des chunks en bas à droite
              */
                QVector<QVector<Chunk::Chunk*> > _chunkBR;
        public:
                /**
                  * Constructeur
                  */
                World();
                /**
                  * Destructeur.
                  * Détruit toutes les entitées présentes
                  * dans le monde
                  */
                virtual ~World();
    };
}
#endif //WORLD_WORLD_H
