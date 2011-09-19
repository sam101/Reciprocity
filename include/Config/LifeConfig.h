#ifndef CONFIG_LIFECONFIG_H
#define CONFIG_LIFECONFIG_H
namespace Config
{
    /**
      * Gère les paramètres de la vie des différantes entités/batiments
      * @brief Gère les paramètres de la vie des différantes entités/batiments
      * @author Sam101
      */
    class LifeConfig
    {
        public:
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
    };
}
#endif //CONFIG_LIFECONFIG_H
