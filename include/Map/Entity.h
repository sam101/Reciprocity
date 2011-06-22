#ifndef MAP_ENTITY_H
#define MAP_ENTITY_H
#include <QtCore/Qt>
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
        public:
    };
}
#endif
