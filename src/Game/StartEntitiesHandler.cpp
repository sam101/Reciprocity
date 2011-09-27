#include <Game/StartEntitiesHandler.h>

#include <Config/EntityConfig.h>
#include <Game/Game.h>
#include <Tools/Random.h>

using namespace Config;
using namespace Tools;
namespace Game
{
    /**
      * Constructeur
      */
    StartEntitiesHandler::StartEntitiesHandler(Game *game, World::World *world) :
    _world(world),
    _game(game)
    {

    }
    /**
      * Ajoute les entités de base à un joueur
      */
    void StartEntitiesHandler::addStartEntities(Player *player)
    {
        qint32 xBase, yBase;
        //On trouve le chunk où spawner les unités
        //On trouve le chunk de départ
        do
        {
            xBase = Random::next(-200,200);
            yBase = Random::next(-200,200);

        } while (_world->getChunkByTile(xBase,yBase)->getType() != Chunk::LAND);
        //On ajoute les entitées de départ au joueur
        for (int i = 0; i < EntityConfig::NB_ENTITIES; i++)
        {
            //On définit la position de l'entité (On s'arrange pour que l'entité ne soie jamais dans de l'eau)
            qint32 xEntity, yEntity;
            qint32 i = 0, j = 0;
            do
            {
                xEntity = xBase + Random::next(-EntityConfig::ENTITY_ZONE,EntityConfig::ENTITY_ZONE) + i;
                yEntity = yBase + Random::next(-EntityConfig::ENTITY_ZONE,EntityConfig::ENTITY_ZONE) + j;
                i += Random::next(-1,1);
                j += Random::next(-1,1);
            } while (_world->getTile(xEntity,yEntity).getType() == Map::SEA);
            //On construit l'entité
            Map::Entity entity(xEntity,yEntity,player->getId());
            //On lui ajoute les ressources de base
            entity.addResource(Map::FOOD,EntityConfig::FOOD_ENTITY);
            entity.addResource(Map::WOOD,EntityConfig::WOOD_ENTITY);
            //On l'ajoute au monde
            _game->addEntity(entity,xEntity,yEntity);
        }
    }
}
