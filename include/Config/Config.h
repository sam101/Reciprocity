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
            /**
              * Port de base du serveur
              */
            static const qint32 SERVER_PORT = 4242;
            /**
              * Taille d'un chunk
              */
            static const qint32 CHUNK_SIZE = 32;
            /**
              * Stocke la taille d'une tile
              */
            static const qint32 TILE_SIZE = 32;
            /**
              * Points de vie de base d'une entité
              */
            static const qint32 BASE_LIFE_POINTS = 100;
            /**
              * Volonté de base d'une entité
              */
            static const qint32 BASE_WILL = 100;

            /**
              * Nombre d'entités de base
              */
            static const qint32 NB_ENTITIES = 8;
            /**
              * Nourriture de base données aux entités
              */
            static const qint32 FOOD_ENTITY = 100;
            /**
              * Bois de base donné aux entités
              */
            static const qint32 WOOD_ENTITY = 100;
            /**
              * Zone dans laquelle les entités sont dispersées en début de partie
              */
            static const qint32 ENTITY_ZONE = 3;
    };
}
#endif //CONFIG_CONFIG_H
