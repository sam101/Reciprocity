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
            /**
              * Taille d'un chunk
              */
            static const int CHUNK_SIZE = 32;
            /**
              * Stocke la taille d'une tile
              */
            static const qint32 TILE_SIZE = 32;
            /**
              * Points de vie de base d'une entité
              */
            static const qint32 BASE_LIFE_POINTS = 100;
    };
}
#endif //CONFIG_CONFIG_H
