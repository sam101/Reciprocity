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
              * Position X du chunk
              */
            qint32 _x;
            /**
              * Position Y du chunk
              */
            qint32 _y;
            /**
              * Type du chunk
              */
            ChunkType _type;
            /**
              * Tableau de tiles du chunk
              */
            QVector<QVector<Map::Tile> > _tiles;
            /**
              * Id des entitées présentes dans le chunk
              */
            QVector<QVector<int> > _entities;

    public:
            /**
              * Constructeur
              */
            Chunk(qint32 x, qint32 y, ChunkType type = SEA);
            /**
              * Renvoie la position x du chunk
              */
            qint32 getX() const;
            /**
              * Renvoie la position y du chunk
              */
            qint32 getY() const;
            /**
              * Renvoie le type du chunk
              */
            ChunkType getType() const;
            /**
              * Renvoie une tile du chunk
              */
            Map::Tile& getTile(int x, int y);
            /**
              * Renvoie une tile du chunk.
              * surchargé constant.
              */
            const Map::Tile& getTile(int x, int y) const;


    };
}
#endif
