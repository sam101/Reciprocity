#include <Game/BuildHandler.h>

#include <Config/CostsConfig.h>

using namespace Config;
namespace Game
{
    /**
      * Constructeur
      */
    BuildHandler::BuildHandler(World::World *world, QList<Player *> &players) :
    _world(world),
    _players(players)
    {

    }
    /**
      * Construit un batiment
      * @return true si réussi, false si échoué
      */
    bool BuildHandler::build(qint32 entityId, Map::BuildingType type)
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
        //On vérifie si l'entité possède les ressources
        switch (type)
        {
            //Construction d'une maison
            case Map::HOUSE:
                return buildHouse(entity);
            break;
            //Construction d'un champ
            case Map::FARMLAND:
                return buildFarmland(entity);
            break;
            //Construction d'une route
            case Map::ROAD:
                return buildRoad(entity);
            break;
            //Construction d'un mur
            case Map::WALL:
                return buildWall(entity);
            break;
            default:
                //On ne fait rien
            break;
        }

        return true;
    }
    /**
      * Construit une maison
      */
    bool BuildHandler::buildHouse(Map::Entity *entity)
    {
        //On vérifie qu'on a assez de ressources
        if (entity->getResource(Map::WOOD) < CostsConfig::COST_HOUSE_WOOD)
        {
            return false;
        }
        //On construit la maison
        if (_world->addBuilding(entity->getX(),entity->getY(),Map::HOUSE,entity->getOwner()))
        {
            //On enlève les ressources à l'entité et on indique qu'elle s'est déplacée
            entity->setHasMoved();
            entity->delRessource(Map::WOOD,CostsConfig::COST_HOUSE_WOOD);
        }
        else
        {
            return false;
        }
        return true;
    }
    /**
      * Construction d'un champ
      */
    bool BuildHandler::buildFarmland(Map::Entity *entity)
    {
        if (entity->getResource(Map::WOOD) < CostsConfig::COST_FARMLAND_WOOD)
        {
            return false;
        }
        //On vérifie que la tile à assez de productivité
        if (_world->getTile(entity->getX(),entity->getY()).getOutput() < CostsConfig::COST_FARMLAND_OUTPUT)
        {
            return false;
        }
        //On construit le champ
        if (_world->addBuilding(entity->getX(),entity->getY(),Map::FARMLAND,entity->getOwner()))
        {
            //On enlève les ressources à l'entité et on indique qu'elle s'est déplacée
            entity->setHasMoved();
            entity->delRessource(Map::WOOD,CostsConfig::COST_FARMLAND_WOOD);
            //On enlève la productivité à la tile
            _world->getTile(entity->getX(),entity->getY()).delOutput(CostsConfig::COST_FARMLAND_OUTPUT);
        }
        else
        {
            return false;
        }
        return true;
    }
    /**
      * Construction d'une route
      */
    bool BuildHandler::buildRoad(Map::Entity *entity)
    {
        if (entity->getResource(Map::STONE) < CostsConfig::COST_ROAD_STONE)
        {
            return false;
        }

        //On construit la route
        if (_world->addBuilding(entity->getX(),entity->getY(),Map::ROAD,entity->getOwner()))
        {
            entity->setHasMoved();
            entity->delRessource(Map::STONE,CostsConfig::COST_ROAD_STONE);
        }
        else
        {
            return false;
        }
        return true;
    }
    /**
      * Construction d'un mur
      */
    bool BuildHandler::buildWall(Map::Entity *entity)
    {
        if (entity->getResource(Map::WOOD) < CostsConfig::COST_WALL_WOOD || entity->getResource(Map::STONE < CostsConfig::COST_WALL_STONE))
        {
            return false;
        }
        //On construit le mur
        if (_world->addBuilding(entity->getX(),entity->getY(),Map::WALL,entity->getOwner()))
        {
            entity->delRessource(Map::WOOD,CostsConfig::COST_WALL_STONE);
            entity->delRessource(Map::STONE,CostsConfig::COST_WALL_WOOD);
            entity->setHasMoved();
        }
        else
        {
            return false;
        }
        return true;
    }
}
