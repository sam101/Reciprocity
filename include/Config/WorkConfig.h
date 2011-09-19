#ifndef CONFIG_WORKCONFIG_H
#define CONFIG_WORKCONFIG_H
#include <QtCore/Qt>
namespace Config
{
    /**
      * Gère les paramètres liés au travail des entités
      * @brief Gère les paramètres liés au travail des entités
      * @author Sam101
      */
    class WorkConfig
    {
        public:
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
#endif //CONFIG_WORKCONFIG_H
