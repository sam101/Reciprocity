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
        protected:
            /**
              * Tableau de tiles du chunk
              */
            QVector<QVector<Map::Tile> > _tiles;
            /**
              * Entitées présentes dans le chunk
              */
            QVector<QVector<Map::Entity*> > _entities;

    public:

    };
}
#endif
