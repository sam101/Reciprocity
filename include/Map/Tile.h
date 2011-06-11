#ifndef MAP_TILE_H
#define MAP_TILE_H
#include <Map/TileType.h>
namespace Map
{
    /**
      * Gère une tile sur la carte
      * @brief Gère une tile sur la carte
      * Une tile est l'élément de base de la carte.
      */
    class Tile
    {
        protected:
            /**
              * Type de la tile
              */
            TileType _type;

    };
}
#endif
