#ifndef CONFIG_ENTITYCONFIG_H
#define CONFIG_ENTITYCONFIG_H
namespace Config
{
    /**
      * Stocke les informations de configuration à propos des entités
      * @brief Informations de configuration à propos des entités
      * @author Sam101
      */
    class EntityConfig
    {
        public:
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


    };
}
#endif //CONFIG_ENTITYCONFIG_H
