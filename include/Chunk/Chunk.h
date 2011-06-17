#ifndef CHUNK_CHUNK_H
#define CHUNK_CHUNK_H
#include <Map/Entity.h>
#include <Map/Tile.h>
#include <QtCore/QVector>
namespace Chunk
{
    /**
      * Contient une partie de la carte
      * @brief Contient une partie de la carte
      * @author Sam101
      */
    class Chunk
    {
        public:
            /**
              * Type du chunk
              */
            enum ChunkType
            {
                SEA = 0,
                ISLAND = 1
            };

        protected:
            /**
              * Type du chunk
              */
            ChunkType _type;
            /**
              * Tableau de tiles du chunk
              */
            QVector<QVector<Map::Tile> > _tiles;
            /**
              * Entitées présentes dans le chunk
              */
            QVector<QVector<Map::Entity*> > _entities;

    public:
            /**
              * Constructeur
              */
            Chunk(ChunkType type = SEA);


    };
}
#endif
