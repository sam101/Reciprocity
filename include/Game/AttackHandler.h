#ifndef GAME_ATTACKHANDLER_H
#define GAME_ATTACKHANDLER_H
#include <World/World.h>
#include <Game/Player.h>
namespace Game
{
    /**
      * Gère la gestion de l'attaque d'une entité sur une entité/batiment
      * @brief Gère la gestion de l'attaque d'une entité sur une entité/batiment
      * @author Sam101
      */
    class AttackHandler
    {
        protected:
            /**
              * Pointeur vers l'objet monde
              */
            World::World *_world;
            /**
              * Tableau des joueurs
              */
            QList<Player*> &_players;
        public:

    };
}
#endif //GAME_ATTACKHANDLER_H
