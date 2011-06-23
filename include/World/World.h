#ifndef WORLD_WORLD_H
#define WORLD_WORLD_H
#include <QtCore/QVector>

#include <Chunk/Chunk.h>
#include <Map/Entity.h>
#include <World/WorldGenerator.h>
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
        friend class WorldGenerator;
        protected:
            /**
              * Pointeur vers le générateur du monde
              */
            WorldGenerator *_generator;
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
             /**
               * Tableau des entités.
               */
             QList<Map::Entity*> _entities;
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
                /**
                  * Renvoie un chunk du monde. Les coordonnées
                  * sont par chunk (et non par tile).
                  * Cette méthode n'est pas const car il y'a possibilité
                  * de génération d'un nouveau chunk à l'appel.
                  */
                Chunk::Chunk* getChunk(int x, int y);
                /**
                  * Renvoie une tile du monde.
                  * N'est pas const car possibiliré de génération d'un chunk.
                  */
                Map::Tile& getTile(int x, int y);
    };   
}
#endif //WORLD_WORLD_H
