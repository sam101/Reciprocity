#ifndef WORLD_WORLDGENERATOR_H
#define WORLD_WORLDGENERATOR_H
#include <Chunk/Chunk.h>
#include <Chunk/ChunkGenerator.h>
#include <QtCore/QList>
#include <QtCore/Qt>
namespace World
{
    class World;
    /**
      * Classe s'occupant de la génération du monde
      * c'est à dire la génération du type des chunk présents
      * dans le monde.
      * Il s'occupe également ensuite de la génération du chunk en lui même.
      * @brief S'occupe de la génération du monde
      * @author Sam101
      */
    class WorldGenerator
    {
        protected:
            /**
              * Pointeur vers le monde à générer
              */
            World *_world;
            /**
              * Redimensionne la taille des tableaux de chunk
              */
            QList<Chunk::Chunk*> _redim(qint32 x, qint32 y);
            /**
              * Générateurs de chunk
              */
            QList<Chunk::ChunkGenerator*> _generators;
            /**
              * Initialise les générateurs de chunk.
              */
            void _initChunkGenerator();
        public:
            /**
              * Constructeur
              */
            WorldGenerator(World *world);
            /**
              * Destructeur
              */
            virtual ~WorldGenerator();
            /**
              * Demande la génération d'un chunk.
              * Peut entrainer en cascade la génération d'autres
              * chunk.
              * @param x Position X du chunk à générer.
              * @param y Position Y du chunk à générer.
              */
            virtual void generate(qint32 x, qint32 y);
    };

}
#endif //WORLD_WORLDGENERATOR_H
