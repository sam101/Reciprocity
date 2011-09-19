#ifndef CONFIG_COSTSCONFIG_H
#define CONFIG_COSTSCONFIG_H
#include <QtCore/Qt>
namespace Config
{
    /**
      * Stocke les informations de configuration relatives aux coûts
      * @brief Stocke les informations de configuration relatives aux coûts
      * @author Sam101
      */
    class CostsConfig
    {
        public:
            /**
              * Coût en bois d'une maison
              */
            static const qint32 COST_HOUSE_WOOD = 50;
            /**
              * Coût en bois d'une route
              */
            static const qint32 COST_ROAD_WOOD = 2;
            /**
              * Coût en bois d'un champ
              */
            static const qint32 COST_FARMLAND_WOOD = 5;
            /**
              * Coût en productivité d'un champ
              */
            static const qint32 COST_FARMLAND_OUTPUT = 50;
            /**
              * Coût en pierre d'une route
              */
            static const qint32 COST_ROAD_STONE = 1;
    };
}
#endif //CONFIG_COSTSCONFIG_H
