#ifndef CONFIG_BASECONFIG_H
#define CONFIG_BASECONFIG_H
#include <QtCore/Qt>
namespace Config
{
    /**
      * Contient les paramètres de configuration sur les informations
      * de base du serveur
      * @brief Informations de base sur le serveur
      * @author Sam101
      */
    class BaseConfig
    {
        //TODO: Permettre la modification de ces valeurs.
        public:
            /**
              * Port de base du serveur
              */
            static const qint32 SERVER_PORT = 4242;
            /**
              * Nombre maximal de joueurs dans le serveur
              */
            static const qint32 MAX_PLAYERS = 8;
            /**
              * Taille d'un chunk
              */
            static const qint32 CHUNK_SIZE = 32;
            /**
              * Stocke la taille d'une tile
              */
            static const qint32 TILE_SIZE = 32;
    };
}
#endif //CONFIG_BASECONFIG_H
