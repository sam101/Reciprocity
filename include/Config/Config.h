#ifndef CONFIG_CONFIG_H
#define CONFIG_CONFIG_H
#include <QtCore/QString>
namespace Config
{
    /**
      * Gère les paramètres de configuration
      * @brief Gère les paramètres de configuration
      * @author Sam101
      */
    class Config
    {
        public:
            //TODO: Faire une classe qui permetterait de modifier ces valeurs

            //Points de vie des batiments
            /**
              * Points de vie d'une maison
              */
            static const qint32 LIFE_HOUSE = 25;
            /**
              * Points de vie gagnés par tour pendant la construction
              */
            static const qint32 LIFE_HOUSE_BUILD = 10;
            /**
              * Points de vie d'un champ
              */
            static const qint32 LIFE_FARMLAND = 5;
            /**
              * Points de vie d'un champ gagnés pendant la construction
              */
            static const qint32 LIFE_FARMLAND_BUILD = 1;
            /**
              * Points de vie d'un champ perdus par utilisation
              */
            static const qint32 LIFE_LOST_FARMLAND = 1;
            /**
              * Points de vie d'une route
              */
            static const qint32 LIFE_ROAD = 25;
            /**
              * Points de vie d'une route gagnés pendant la construction
              */
            static const qint32 LIFE_ROAD_BUILD = 25;
            //Gestion du moral
            /**
              * Moral perdu par tour quand non sur une maison
              */
            static const qint32 WILL_LOST_TURN = 1;
            /**
              * Moral gagné quand sur une maison
              */
            static const qint32 WILL_HOUSE = 5;
            /**
              * Moral perdu quand l'entité coupe du bois
              */
            static const qint32 WILL_LOST_FOREST = 10;
            /**
              * Moral perdu quand l'entité creuse dans la montagne
              */
            static const qint32 WILL_LOST_MOUNTAIN = 20;
            //Ressources gagnées en travaillant
            /**
              * Bois gagné en coupant du bois
              */
            static const qint32 FOREST_WOOD_BY_WORK = 10;
            /**
              * Facteur d'aléatoire du bois
              */
            static const qint32 FOREST_WOOD_RANDOM = 40;
            /**
              * Nouriture gagnée dans un champ
              */
            static const qint32 FARMLAND_FOOD_BY_WORK = 5;
            /**
              * Facteur d'aléatoire du champ
              */
            static const qint32 FARMLAND_FOOD_RANDOM = 10;
            /**
              * Pierre gagnée en creusant dans la montagne
              */
            static const qint32 MOUNTAIN_STONE_BY_WORK = 10;
            /**
              * Facteur d'aléatoire de la collecte de pierre
              */
            static const qint32 MOUNTAIN_STONE_RANDOM = 10;
            //Paramètres sur la productivité
            /**
              * Productivité regagnée par tour pour les Tiles
              */
            static const qint16 OUTPUT_TURN = 1;
            /**
              * Productivité minimale pour que la case retrouve sa productivité
              */
            static const qint16 OUTPUT_MINIMAL = 5;
            //Productivité des tiles
            /**
              * Productivité minimale des plaines.
              */
            static const qint32 LOWLAND_MIN_OUTPUT = 50;
            /**
             * Productivité maximale des plaines
             */
            static const qint32 LOWLAND_MAX_OUTPUT = 100;
            /**
              * Productivité supplémentaire des plaines
              */
            static const qint32 LOWLAND_ADD_OUTPUT = 25;
            /**
              * Quantité maximale de productivité supplémentaire des plaines
              */
            static const qint32 LOWLAND_ADD_OUTPUT_NB = 2;
            /**
              * Productivité minimale des montagnes
              */
            static const qint32 MOUNTAIN_MIN_OUTPUT = 25;
            /**
              * Productivité maximale des montagnes
              */
            static const qint32 MOUNTAIN_MAX_OUTPUT = 110;

    };
}
#endif //CONFIG_CONFIG_H
