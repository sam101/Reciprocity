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
              * Productivité regagnée par tour pour les Tiles
              */
            static const qint16 OUTPUT_TURN = 1;
            /**
              * Productivité minimale pour que la case retrouve sa productivité
              */
            static const qint16 OUTPUT_MINIMAL = 5;

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
            static const qint32 ENTITY_ZONE = 5;
            /**
              * Nombre de déplacements qu'une entité peut faire par tour
              */
            static const qint32 ENTITY_MOVE = 3;
            //Liste des couts des batiments
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
            //Points de vie des batiments
            /**
              * Points de vie d'une maison
              */
            static const qint32 LIFE_HOUSE = 25;
            /**
              * Points de vie d'un champ
              */
            static const qint32 LIFE_FARMLAND = 100;
            /**
              * Points de vie d'un champ perdus par utilisation
              */
            static const qint32 LIFE_LOST_FARMLAND = 20;
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
            //Ressources gagnées en travaillant
            /**
              * Bois gagné en coupant du bois
              */
            static const qint32 FOREST_WOOD_BY_WORK = 10;
    };
}
#endif //CONFIG_CONFIG_H
