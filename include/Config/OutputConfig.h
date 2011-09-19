#ifndef CONFIG_OUTPUTCONFIG_H
#define CONFIG_OUTPUTCONFIG_H
#include <QtCore/Qt>
namespace Config
{
    /**
      * Stocke les informations sur la productivité
      * @brief Stocke les informations sur la productivité
      * @author Sam101
      */
    class OutputConfig
    {
        public:
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
#endif //CONFIG_OUTPUTCONFIG_H
