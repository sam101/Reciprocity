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
                    FARMING_CAPABLE = 4
              };

        protected:
           /**
             * Capacités de la tile
             */
           qint32 _flags;
           /**
             * Type de la tile
             */
           TileType _type;
           /**
             * Productivité de la tile
             */
          qint32 _output;
          /**
            * Position X de la tile
            */
          qint32 _x;
          /**
            * Position Y de la tile
            */
          qint32 _y;

      public:
          /**
            * Constructeur
            */
          Tile(qint32 x = 0, qint32 y = 0,qint32 flags = PASSABLE, TileType type = NOTHING  , qint32 output = 0);
          /**
            * Renvoie les capacités de la tile
            */
          qint32 getFlags() const;
          /**
            * Renvoie le type de la tile.
            */
          TileType getType() const;
          /**
            * Renvoie la productivité de la tile.
            */
          qint32 getOutput() const;

          /**
            * Définit les paramètres de la tile
            */
          void setTile(TileType type, qint32 flags = 0);
          /**
            * Définit le rendement de la tile.
            */
          void setOutput(qint32 output);


    };
}
#endif
