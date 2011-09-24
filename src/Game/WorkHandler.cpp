#include <Game/WorkHandler.h>

#include <Config/LifeConfig.h>
#include <Config/WorkConfig.h>

#include <Tools/Random.h>

using namespace Tools;
using namespace Config;

namespace Game
{
    /**
      * Constructeur
      */
    WorkHandler::WorkHandler(World::World *world, QList<Player*>& players) :
    _world(world),
    _players(players)
    {

    }
    /**
      * Fait travailler une entité
      * @return true si réussi, false si impossible
      */
    bool WorkHandler::work(qint32 entityId)
    {
        Map::Entity *entity = _world->getEntity(entityId);
        //Verification de l'id de l'entité
        if (entity == NULL)
        {
            return false;
        }
        //On vérifie si l'entité ne s'est pas déplacée.
        if (entity->hasMoved())
        {
            return false;
        }
        //On agit différament selon ce sur quoi l'entité se trouve.
        Map::Tile &tile = _world->getTile(entity->getX(),entity->getY());
        Map::Building &building = _world->getBuilding(entity->getX(),entity->getY());
        switch (tile.getType())
        {
            //Sur une forêt, une entité coupe du bois
            case Map::FOREST:
                return forestWork(entity,tile,building);
            break;
            //Sur une montagne, une entité peut recolter de la pierre.
            case Map::MOUNTAIN:
                return mountainWork(entity,tile,building);
            break;
            default:
                //Si la tile n'est pas spéciale, on teste le batiment
                switch (building.getType())
                {
                    //Si c'est un champ, l'entité recupère de la nouriture
                    case Map::FARMLAND:
                    break;
                    default:
                        return farmlandWork(entity,building);
                    break;
                }

            break;
        }
        return false;
    }
    /**
      * Fait travailler une entité dans une forêt
      */
    bool WorkHandler::forestWork(Map::Entity *entity, Map::Tile &tile, Map::Building &building)
    {
        //On vérifie si la forêt est pas morte ?
        if (tile.getOutput() < WorkConfig::FOREST_WOOD_BY_WORK)
        {
            return false;
        }
        //On vérifie que il n'y'a pas de batiments
        if (building.getType() != Map::NONE)
        {
            return false;
        }
        //On retire le moral à l'entité
        entity->delWill(EntityConfig::WILL_LOST_FOREST);
        //On retire la productivité à la forêt
        tile.delOutput(WorkConfig::FOREST_WOOD_BY_WORK);
        //On rajoute le bois à l'entité
        entity->addResource(Map::WOOD,WorkConfig::FOREST_WOOD_BY_WORK * (entity->getWill() + Random::next(-WorkConfig::FOREST_WOOD_RANDOM,WorkConfig::FOREST_WOOD_RANDOM)) / 100);
        //On indique que l'entité s'est déplacée
        entity->setHasMoved();
        //On retourne que tout s'est bien passé
        return true;
    }
    /**
      * Fait travailler une entité dans une montagne
      */
    bool WorkHandler::mountainWork(Map::Entity *entity, Map::Tile &tile, Map::Building &building)
    {
        //On vérifie qu'on à pas détruit la montagne
        if (tile.getOutput() <  WorkConfig::MOUNTAIN_STONE_BY_WORK / 2)
        {
            return false;
        }
        //On vérifie qu'il y'a pas de batiments.
        if (building.getType() != Map::NONE)
        {
            return false;
        }
        //On retire le moral a l'entité
        entity->delWill(EntityConfig::WILL_LOST_MOUNTAIN);
        //On retire la productivité à la montagne
        tile.delOutput(WorkConfig::MOUNTAIN_STONE_BY_WORK / 2);
        //On ajoute la pierre à l'entité
        entity->addResource(Map::STONE,WorkConfig::MOUNTAIN_STONE_BY_WORK * (entity->getWill() + Random::next(-WorkConfig::MOUNTAIN_STONE_RANDOM,WorkConfig::MOUNTAIN_STONE_RANDOM)) / 100);
        //On indique que l'entité s'est déplacée
        entity->setHasMoved();
        //On retourne que tout s'est bien passé
        return true;
    }
    /**
      * Fait travailler une entité dans un champ
      */
    bool WorkHandler::farmlandWork(Map::Entity *entity, Map::Building &building)
    {
        //On ne peut utiliser qu'un farmland terminé
        if (!building.isFinished())
        {
            return false;
        }
        //On retire des points de vie au champ
        building.damage(LifeConfig::LIFE_LOST_FARMLAND);
        if (building.getLifePoints() <= 0)
        {
            building.setType(Map::NONE);
        }
        //On rajoute de la nouriture à l'entité
        entity->addResource(Map::FOOD,WorkConfig::FARMLAND_FOOD_BY_WORK * (entity->getWill() + Random::next(-WorkConfig::FARMLAND_FOOD_RANDOM,WorkConfig::FARMLAND_FOOD_RANDOM)) / 100);
        //On retourne que tout s'est bien passé
        return true;
    }
}
