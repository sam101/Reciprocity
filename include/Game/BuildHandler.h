#ifndef GAME_BUILDHANDLER_H
#define GAME_BUILDHANDLER_H
#include <Game/Player.h>
#include <World/World.h>
namespace Game
{
    /**
      * Gère la construction de batiments
      * @brief Gère la construction de batiments
      * @author Sam101
      */
    class BuildHandler
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
            BuildHandler(World::World *world, QList<Player*> &players);
            /**
              * Construit un batiment
              * @return true si réussi, false si échoué
              */
            bool build(qint32 entityId, Map::BuildingType type);
        protected:
            /**
              * Construction d'une maison
              */
            bool buildHouse(Map::Entity *entity);
            /**
              * Construction d'un champ
              */
            bool buildFarmland(Map::Entity *entity);
            /**
              * Construction d'une route
              */
            bool buildRoad(Map::Entity *entity);
    };
}
#endif //GAME_BUILDHANDLER_H

