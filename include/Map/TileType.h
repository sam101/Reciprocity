#ifndef MAP_TILETYPE_H
#define MAP_TILETYPE_H
namespace Map
{
    /**
      * Représente tout les types possibles d'une tile
      * dans la carte
      * @brief Représente tout les types possibles d'une tile
      * @author Sam101
      */
    enum TileType
    {
        /**
          * Rien du tout
          */
        NOTHING = 0,
        /**
          * Mer
          */
        SEA = 1,
        /**
          * Plaines
          */
        LOWLAND = 2,
        /**
          * Forêt
          */
        FOREST = 3,
        /**
          * Lac
          */
        LAKE = 4,
        /**
          * Rivière
          */
        RIVER = 5,
        /**
          * Montagnes
          */
        MOUNTAIN = 6,
        /**
          * Plage
          */
        BEACH = 7
    };
}
#endif
