#ifndef CHUNK_CHUNK_H
#define CHUNK_CHUNK_H
#include <Chunk/ChunkType.h>
#include <Map/Building.h>
#include <Map/Entity.h>
#include <Map/Tile.h>
#include <QtCore/QDataStream>
#include <QtCore/QSet>
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
              * Magic number de Chunk
              */
            static const qint32 CHUNK_MAGICNUMBER = 0x42424201;
            /**
              * Numéro de version de Chunk
              */
            static const qint32 CHUNK_VERSION = 1;
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
              * Tableau des batiments du chunk
              */
            QVector<QVector<Map::Building> > _buildings;
            /**
              * Id des entitées présentes dans le chunk
              */
            QSet<qint32> _entities;

    public:
            /**
              * Constructeur
              */
            Chunk(qint32 x = 0, qint32 y = 0, ChunkType type = SEA);
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
            Map::Tile& getTile(qint32 x, qint32 y);
            /**
              * Renvoie une tile du chunk.
              * surchargé constant.
              */
            const Map::Tile& getTile(qint32 x, qint32 y) const;
            /**
              * Renvoie une tile du chunk en position absolue
              */
            Map::Tile& getTileAbs(qint32 x, qint32 y);
            /**
              * Renvoie une tile du chunk en position absolue
              * surchargé constant.
              */
            const Map::Tile& getTileAbs(qint32 x, qint32 y) const;
            /**
              * Renvoie un batiment du chunk
              */
            Map::Building& getBuilding(qint32 x, qint32 y);
            /**
              * Renvoie un batiment du chunk.
              * Surchargé constant
              */
            const Map::Building& getBuilding(qint32 x, qint32 y) const;
            /**
              * Renvoie un batiment du chunk en position absolue
              */
            Map::Building& getBuildingAbs(qint32 x, qint32 y);
            /**
              * Renvoie un batiment du chunk en position absolue
              * Surchargé constant
              */
            const Map::Building& getBuildingAbs(qint32 x, qint32 y) const;
            /**
              * Défini le type du chunk
              */
            void setType(ChunkType type);
            /**
              * Ajoute une entité au chunk
              */
            void addEntity(qint32 id);
            /**
              * Supprime une entité du chunk
              */
            void delEntity(qint32 id);
            /**
              * Renvoie si l'entité fait partie du chunk
              */
            bool hasEntity(qint32 id) const;
            /**
              * Stocke un chunk dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const Chunk &c);
            /**
              * Recupère un chunk d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, Chunk &c);
    };
}
#endif
