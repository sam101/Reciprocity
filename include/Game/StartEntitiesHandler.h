#ifndef GAME_STARTENTITIESHANDLER_H
#define GAME_STARTENTITIESHANDLER_H
#include <World/World.h>
namespace Game
{
    class Player;
    class Game;
    /**
      * Gère la gestion des entités de base des joueurs
      * @brief Gère la gestion des entités de base des joueurs
      * @author Sam101
      */
    class StartEntitiesHandler
    {
        protected:
            /**
              * Pointeur vers l'objet monde
              */
            World::World *_world;
            /**
              * Pointeur vers l'objet jeu
              */
            Game *_game;
        public:
            /**
              * Constructeur
              */
            StartEntitiesHandler(Game *game, World::World *world);
            /**
              * Ajoute les entités de base à un joueur
              */
            void addStartEntities(Player *player);
    };
}
#endif //GAME_STARTENTITIESHANDLER_H
