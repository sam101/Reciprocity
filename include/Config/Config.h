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
            //TODO: Faire une classe qui permetterait de charger/modifier les valeurs

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


    };
}
#endif //CONFIG_CONFIG_H
