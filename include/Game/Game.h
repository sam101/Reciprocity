#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <World/World.h>
namespace Game
{
    /**
      * Gère toutes les actions liées aux jeu: Gestion du monde
       *, de ce que contient le monde, des actions, des joueurs
       * @brief Gère toutes les actions liées au jeu
       * @author Sam101
       */
    class Game
    {
        protected:
            /**
              * Pointeur vers le monde
              */
            World::World *_world;
            /**
              * Indique si la partie à commencé
              */
            bool _hasBegun;
        public:
            /**
              * Constructeur
              */
            Game();
            /**
              * Destructeur
              */
            virtual ~Game();
            /**
              * Renvoie le monde actuel
              */
            World::World* getWorld();
            /**
              * Renvoie le monde actuel
              * surchargé constant
              */
            const World::World* getWorld() const;
            /**
              * Renvoie si la partie a commencé
              */
            bool hasBegun() const;
    };
}
#endif //GAME_GAME_H
