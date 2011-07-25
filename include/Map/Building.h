#ifndef MAP_BUILDING_H
#define MAP_BUILDING_H
#include <QtCore/QDataStream>
#include <QtCore/Qt>
#include <Map/BuildingType.h>
namespace Map
{
    /**
      * Stocke les informations sur un batiment
      * @brief Stocke les informations sur un batiment
      * @author Sam101
      */
    class Building
    {
        public:
            /**
              * Magic number de Building
              */
            static const qint32 BUILDING_MAGICNUMBER = 0x42424204;
            /**
              * Numéro de version de Building
              */
            static const qint32 BUILDING_VERSION = 1;
        protected:
            /**
              * Type du batiment
              */
            BuildingType _type;
            /**
              * Niveau du batiment
              */
            qint32 _level;
            /**
              * Points de vie du batiment
              */
            qint32 _lifePoints;
            /**
              * Points de vie maximums du batiment
              */
            qint32 _maxLifePoints;
            /**
              * Position X du batiment
              */
            qint32 _x;
            /**
              * Position Y du batiment
              */
            qint32 _y;
        public:
            /**
              * Constructeur
              */
            Building(qint32 x = 0, qint32  y = 0, BuildingType type = NONE, qint32 level = 0, qint32 lifePoints = 0, qint32 maxLifePoints = 0);
            /**
              * Renvoie le type du batiment
              */
            BuildingType getType() const;
            /**
              * Renvoie le niveau du batiment
              */
            qint32 getLevel() const;
            /**
              * Renvoie les points de vie du batiment
              */
            qint32 getLifePoints() const;
            /**
              * Renvoie les points de vie maximums du batiment
              */
            qint32 getMaxLifePoints() const;
            /**
              * Renvoie la position X du batiment
              */
            qint32 getX() const;
            /**
              * Renvoie la position Y du batiment
              */
            qint32 getY() const;
            /**
              * Envoie un batiment dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, Building &b);
            /**
              * Recupère un batiment d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, Building &b);
    };
}
#endif //MAP_BUILDING_H
