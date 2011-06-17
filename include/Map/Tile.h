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
      public:
          /**
            * Renvoie les capacités de la tile
            */
          int getFlags() const;
          /**
            * Renvoie le type de la tile.
            */
          TileType getType() const;
          /**
            * Renvoie la productivité de la tile.
            */
          qint32 getOutput() const;
          /**
            * Renvoie la position X de la tile dans le tileset.
            */
          qint32 getX() const;
          /**
            * Renvoie la position Y de la tile dans le tileset.
            */
          qint32 getY() const;


    };
}
#endif
