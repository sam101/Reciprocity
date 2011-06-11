#ifndef MAP_TILE_H
#define MAP_TILE_H
#include <Map/TileType.h>
#include <QtCore/Qt>
namespace Map
{
    /**
      * Gère une tile sur la carte
      * @brief Gère une tile sur la carte
      * Une tile est l'élément de base de la carte.
      */
    class Tile
    {
        public:
            /**
              * Capacités Possibles de la tile
              */
              enum TileFlags
              {
                    PASSABLE = 1,
                    BOAT_PASSABLE = 2,
                    FARMING = 4
              };

        protected:
           /**
             * Capacités de la tile
             */
           int _flags;
           /**
             * Type de la tile
             */
           TileType _type;
           /**
             * Productivité de la tile
             */
          qint32 _output;

          /**
            * Position X dans le tileset.
            */
          qint32 _x;
          /**
            * Position Y dans le tileset.
            */
          qint32 _y;

    };
}
#endif
