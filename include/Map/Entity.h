#ifndef MAP_ENTITY_H
#define MAP_ENTITY_H
#include <QtCore/Qt>
#include <Map/EntityAbilities.h>
namespace Map
{
    /**
      * Gère une entité présente sur la carte
      * @brief Gère une entité présente sur la carte
      * @author Sam101
      */
    class Entity
    {
        protected:
            /**
              * Position X de l'entité
              */
            qint32 _x;
           /**
             * Position Y de l'entité
             */
            qint32 _y;
            /**
              * Points de vie actuels de l'entité
              */
            qint32 _lifePoints;
            /**
              * Points de vie maximums de l'entité
              */
            qint32 _maxLifePoints;
            /**
              * Indique si l'entité s'est déjà déplacée
              */
            bool _hasMoved;
            /**
              * Indique si l'entité est morte
              */
            bool _dead;
            /**
              * Age de l'entité
              */
            qint32 _age;
            /**
              * Niveaux de l'entité
              */
            QVector<qreal> _abilities;
        public:
    };
}
#endif
