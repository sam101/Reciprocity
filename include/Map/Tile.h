#ifndef MAP_TILE_H
#define MAP_TILE_H
#include <Map/ResourceType.h>
#include <Map/TileType.h>
#include <QtCore/QDataStream>
#include <QtCore/Qt>
#include <QtCore/QVector>
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
              * "Magic number" de Tile
              */
            static const qint32 TILE_MAGICNUMBER = 0x42424200;
            /**
              * Numéro de version de Tile
              */
            static const qint32 TILE_VERSION = 1;
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
           qint8 _flags;
           /**
             * Type de la tile
             */
           TileType _type;
           /**
             * Productivité de la tile
             */
          qint16 _output;
          /**
            * Productivité maximale
            */
          qint16 _maxOutput;
          /**
            * Position X de la tile
            */
          qint32 _x;
          /**
            * Position Y de la tile
            */
          qint32 _y;
         /**
           * Ressources présentes sur la Tile
           */
          qint16 _resources[Map::MAX];
      public:
          /**
            * Constructeur
            */
          Tile(qint32 x = 0, qint32 y = 0,qint8 flags = PASSABLE, TileType type = NOTHING  , qint32 output = 0);
          /**
            * Renvoie la position X de la tile
            */
          qint32 getX() const;
          /**
            * Renvoie la position Y de la tile
            */
          qint32 getY() const;
          /**
            * Renvoie les capacités de la tile
            */
          qint8 getFlags() const;
          /**
            * Renvoie le type de la tile.
            */
          TileType getType() const;
          /**
            * Renvoie la productivité de la tile.
            */
          qint16 getOutput() const;
          /**
            * Renvoie la productivité maximale de la tile
            */
          qint16 getMaxOutput() const;
          /**
            * Renvoie une ressource de la tile
            */
          qint16 getResource(qint32 id);

          /**
            * Définit les paramètres de la tile
            */
          void setTile(TileType type, qint32 flags = 0);
          /**
            * Définit le rendement de la tile.
            */
          void setOutput(qint16 output);
          /**
            * Diminue la productivité de la tile
            */
          void delOutput(qint16 output);
          /**
            * Remonte la productivité de la tile.
            * Ne peut pas monter au dessus de la productivité maximale
            */
          void restoreOutput(qint16 output);
          /**
            * Change la valeur d'une ressource
            */
          void setResource(qint32 id, qint16 value);
          /**
            * Ajoute une ressource à la tile
            */
          void addResource(qint32 id, qint16 value);
          /**
            * Enlève une ressource à la tile
            */
          void delResource(qint32 id, qint16 value);
          /**
            * Définit la tile comme étant une plaine
            */
          void setAsLowLand();
          /**
            * Définit la tile comme étant une montagne
            */
          void setAsMountain();
          /**
            * Définit la tile comme étant une foret
            */
          void setAsForest();
          /**
            * Définit la tile comme étant un lac
            */
          void setAsLake();
          /**
            * Définit la tile comme étant une rivière
            */
          void setAsRiver();
          /**
            * Définit la tile comme étant de la mer.
            */
          void setAsSea();
          /**
            * Définit la tile comme étant une plage
            */
          void setAsBeach();
          /**
            * Définit la tile comme étant un marais
            */
          void setAsSwamp();
          /**
            * Définit la tile comme étant un volcan
            */
          void setAsVolcano();
          /**
            * Stocke une tile dans un QDataStream
            */
          friend QDataStream& operator<<(QDataStream &out, const Tile &t);
         /**
           * Recupère une tile d'un QDataStream
           */
          friend QDataStream& operator>>(QDataStream &in, Tile &t);
    };
}
#endif
