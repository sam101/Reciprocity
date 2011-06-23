#ifndef MAP_ENTITY_H
#define MAP_ENTITY_H
#include <Config/Config.h>
#include <QtCore/Qt>
#include <QtCore/QVector>
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
              * Id du propriétaire de l'entité.
              */
            qint32 _owner;
            /**
              * Volonté de l'entité.
              */
            qint32 _will;
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
            /**
              * Constructeur
              */
            Entity(qint32 x = 0, qint32 y = 0, qint32 owner = -1, qint32 lifePoints = Config::Config::BASE_LIFE_POINTS, qint32 will = Config::Config::BASE_WILL, qint32 age = 0);
            /**
              * Renvoie la position X de l'entité
              */
            qint32 getX() const;
            /**
              * Renvoie la position Y de l'entité
              */
            qint32 getY() const;
            /**
              * Renvoie les points de vie de l'entité
              */
            qint32 getLifePoints() const;
            /**
              * Renvoie les points de vie maximums de l'entité
              */
            qint32 getMaxLifePoints() const;
            /**
              * Renvoie le propriétaire de l'entité
              */
            qint32 getOwner() const;
            /**
              * Renvoie la volonté de l'entité.
              */
            qint32 getWill() const;
            /**
              * Renvoie si l'entité s'est déjà déplacée
              */
            bool hasMoved() const;
            /**
              * Renvoie si l'entité est morte
              */
            bool isDead() const;
            /**
              * Renvoie l'age de l'entité
              */
            qint32 getAge() const;
            /**
              * Change la position de l'entité.
              */
            void setXY(qint32 x, qint32 y);
            /**
              * Déplace l'entité
              */
            void move(qint32 x, qint32 y);
            /**
              * Change la volonté de l'entité.
              */
            void setWill(qint32 will);
            /**
              * Ajoute à la volonté de l'entité.
              */
            void addWill(qint32 will);
            /**
              * Enlève de la volonté à l'entité
              */
            void delWill(qint32 will);
            /**
              * Tue l'entité
              */
            void kill();
            /**
              * Ajoute un à l'age de l'entité
              */
            void age();
    };
}
#endif
