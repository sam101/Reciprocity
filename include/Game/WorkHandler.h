#ifndef GAME_WORKHANDLER_H
#define GAME_WORKHANDLER_H
#include <World/World.h>
#include <Game/Player.h>
namespace Game
{
    /**
      * Gère les différantes actions de travail des entités
      * @brief Gère les différantes actions de travail des entités
      * @author Sam101
      */
    class WorkHandler
    {
        protected:
            /**
              * Pointeur vers le monde
              */
            World::World *_world;
            /**
              * Tableau des joueurs
              */
            QList<Player*> &_players;
        public:
            /**
              * Constructeur
              */
            WorkHandler(World::World *world, QList<Player*>& players);
            /**
              * Fait travailler une entité
              * @return true si réussi, false si impossible
              */
            bool work(qint32 entityId);
    };
}
#endif //GAME_WORKHANDLER_H
