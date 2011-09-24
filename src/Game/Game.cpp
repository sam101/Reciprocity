#include <Game/Game.h>
#include <Config/BaseConfig.h>
#include <Config/CostsConfig.h>
#include <Config/EntityConfig.h>
#include <Config/LifeConfig.h>
#include <Config/WorkConfig.h>

#include <QtCore/QDebug>
#include <Config/Config.h>
#include <Tools/Random.h>

using namespace Config;
using namespace Tools;
namespace Game
{
    /**
      * Constructeur
      */
    Game::Game() :
    _workHandler(NULL),
    _world(NULL),
    _turn(0),
    _hasBegun(false)
    {
        //On alloue l'objet de monde
        _world = new World::World;
        //On alloue les handlers
        _workHandler = new WorkHandler(_world,_players);
    }
    /**
      * Destructeur
      */
    Game::~Game()
    {
        if (_world != NULL)
        {
            delete _world;
        }
        for (int i = 0; i < _players.size(); i++)
        {
            delete _players[i];
        }
        //On détruit les handlers
        delete _workHandler;
    }
    /**
      * Renvoie le monde actuel
      */
    World::World* Game::getWorld()
    {
        return _world;
    }
    /**
      * Renvoie le monde actuel
      * Surchargé constant.
      */
    const World::World* Game::getWorld() const
    {
        return _world;
    }
    /**
      * Renvoie si la partie a commencé
      */
    bool Game::hasBegun() const
    {
        return _hasBegun;
    }
    /**
      * Renvoie le tour actuel
      */
    qint32 Game::getTurn() const
    {
        return _turn;
    }
    /**
      * Renvoie une entité
      */
    Map::Entity* Game::getEntity(qint32 id)
    {
        return _world->getEntity(id);
    }
    /**
      * Renvoie un joueur
      */
    Player* Game::getPlayer(qint32 id)
    {
        return _players[id];
    }
    /**
      * Renvoie un joueur.
      * Surchargé constant
      */
    const Player* Game::getPlayer(qint32 id) const
    {
        return _players[id];
    }
    /**
      * Ajoute une entité à la partie
      */
    void Game::addEntity(const Map::Entity &entity, qint32 x, qint32 y)
    {
        //On l'ajoute au monde
        qint32 id = _world->addEntity(entity,x,y);
        //On l'ajoute au joueur
        if (entity.getOwner() < 0 || entity.getOwner() >= _players.size() )
        {
            return;
        }
        _players[entity.getOwner()]->addEntity(id);

    }

    /**
      * Ajoute un joueur à la partie
      */
    Player* Game::addPlayer(QString login, QString hash)
    {
        //On ajoute l'objet "Player"
        _players.append(new Player(_players.size(),login,hash));
        //Si il est le premier joueur, on lui donne les droits d'administrateur.
        if (canBeAdmin(login,hash))
        {
            qDebug() << "Le joueur" << login << "est administrateur";
            _players.last()->setAdmin(true);
        }
        //On lui ajoute ses entités/ressources "de base".
        addStartEntities(_players.last());

        //On renvoie l'objet Player
        return _players.last();
    }
    /**
      * Renvoie si le joueur existe
      */
    bool Game::playerExists(QString login) const
    {
        return findPlayer(login) != NULL;
    }
    /**
      * Cherche un joueur dans la liste des joueurs
      */
    Player* Game::findPlayer(QString login) const
    {
        for (int i = 0; i < _players.size(); i++)
        {
            if (_players[i]->getLogin() == login)
            {
                return _players[i];
            }
        }
        return NULL;
    }

    /**
      * Re-loggue un joueur qui était déjà deconnecté.
      * Renvoie vrai si l'opération à réussi.
      */
    bool Game::playerBack(QString login, QString hash)
    {
        //On recupère un pointeur vers le joueur
        Player *player = findPlayer(login);
        //Si le joueur n'existe pas
        if (player == NULL)
        {
            return false;
        }
        //On vérifie que le hash est bon.
        if (player->getHash() == hash)
        {
            //On indique que le joueur est en ligne
            player->setOnline();
            //On indique que l'opération s'est bien passée
            return true;
        }
        return false;
    }
    /**
      * Renvoie les chunks sur lequel le joueur est présent
      */
    QSet<Chunk::Chunk*> Game::getPlayerChunks(Player *player)
    {
        QSet<Chunk::Chunk*> c;
        //TODO: Faire un cache.
        Map::Entity *entity;
        Chunk::Chunk *chunk;
        for (int i = 0; i < player->getEntities().size(); i++)
        {
            entity = _world->getEntity(player->getEntities()[i]);
            chunk = _world->getChunkByTile(entity->getX(),entity->getY());
            c << chunk;
            //On ajoute les chunk adjacents
            c << _world->getChunk(_world->getXChunk(chunk->getX() - BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY())));
            c << _world->getChunk(_world->getXChunk(chunk->getX() + BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY())));
            c << _world->getChunk(_world->getXChunk(chunk->getX() ),_world->getYChunk((chunk->getY() - BaseConfig::CHUNK_SIZE)));
            c << _world->getChunk(_world->getXChunk(chunk->getX() ),_world->getYChunk((chunk->getY() + BaseConfig::CHUNK_SIZE)));
            c << _world->getChunk(_world->getXChunk(chunk->getX() - BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY() - BaseConfig::CHUNK_SIZE)));
            c << _world->getChunk(_world->getXChunk(chunk->getX() - BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY() + BaseConfig::CHUNK_SIZE)));
            c << _world->getChunk(_world->getXChunk(chunk->getX() + BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY() - BaseConfig::CHUNK_SIZE)));
            c << _world->getChunk(_world->getXChunk(chunk->getX() + BaseConfig::CHUNK_SIZE),_world->getYChunk((chunk->getY() + BaseConfig::CHUNK_SIZE)));
        }
        return c;
    }
    /**
      * Renvoie les entités d'un groupe de chunks
      */
    QList<Map::Entity*> Game::getPlayerEntities(Player *player, QSet<Chunk::Chunk*> chunks)
    {
        Q_UNUSED(player)
        //TODO: Ajouter un cache
        QList<Map::Entity*> l;
        //On parcourt la liste des chunks
        QSetIterator<Chunk::Chunk*> it(chunks);
        while (it.hasNext())
        {
            //On recupère le chunk
            Chunk::Chunk *chunk = it.next();
            //On itère sur la liste des entités du chunk
            QSetIterator<qint32> itEntity(chunk->getEntities());
            while (itEntity.hasNext())
            {
                /*
                 * On recupère le pointeur vers l'entité
                 * et on l'ajoute à la liste
                 */
                l << getEntity(itEntity.next());
            }
        }
        return l;
    }
    /**
      * Commence la partie
      */
    void Game::beginGame()
    {
        _turn = 1;
        _hasBegun = true;
    }
    /**
      * Déplace une entité.
      * @return Vrai si réussi, faux si raté.
      */
    bool Game::moveEntity(qint32 id, qint32 x, qint32 y, qint32 applicant)
    {
        //TODO: Vérifier qu'on finit pas dans un obstacle
        //On vérifie que l'entité existe
        if (_world->getEntity(id) == NULL)
        {
            return false;
        }
        //On vérifie que le joueur n'a pas demandé trop de déplacement
        if ((abs(x) + abs(y)) > EntityConfig::ENTITY_MOVE)
        {
            return false;
        }
        //On vérifie le propriétaire
        if (applicant != _world->getEntity(id)->getOwner())
        {
            return false;
        }
        //On déplace l'entité.
        _world->moveEntity(id,x,y);
        return true;
    }
    /**
      * Commence un nouveau tour
      */
    void Game::newTurn()
    {
        //On incrémente le compteur de tours
        _turn++;
        //On propage la demande de nouveau tour dans le monde.
        _world->newTurn();
        //On remet à zéro le fait que les joueurs ont fini leur tour
        for (int i = 0; i < _players.size(); i++)
        {
            _players[i]->resetEndTurn();
        }
    }

    /**
      * Renvoie si le joueur peut être administrateur
      */
    bool Game::canBeAdmin(QString login, QString hash)
    {
        Q_UNUSED(login)
        Q_UNUSED(hash)
        //Si il y'a qu'un seul joueur, il est forcément administrateur
        if (_players.size() == 1)
        {
            return true;
        }
        //Enfin, on vérifie si le joueur est seul dans la partie
        int i = 0;
        while (i < _players.size() - 1)
        {
            if (_players[i]->isOnline())
            {
                return false;
            }
            i++;
        }
        //Si on en a trouvé aucun, alors il est bien admin.
        return true;
    }
    /**
      * Ajoute les entités de base à un joueur
      */
    void Game::addStartEntities(Player *player)
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
            addEntity(entity,xEntity,yEntity);
        }
    }
    /**
      * Construit un batiment
      * @return true si réussi, false si échoué
      */
    bool Game::build(qint32 entityId, Map::BuildingType type)
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
                //On vérifie qu'on a assez de ressources
                if (entity->getResource(Map::WOOD) < CostsConfig::COST_HOUSE_WOOD)
                {
                    return false;
                }
                //On construit la maison
                if (_world->addBuilding(entity->getX(),entity->getY(),type,entity->getOwner()))
                {
                    //On enlève les ressources à l'entité et on indique qu'elle s'est déplacée
                    entity->setHasMoved();
                    entity->delRessource(Map::WOOD,CostsConfig::COST_HOUSE_WOOD);
                }
                else
                {
                    return false;
                }
            break;
            //Construction d'un champ
            case Map::FARMLAND:
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
                if (_world->addBuilding(entity->getX(),entity->getY(),type,entity->getOwner()))
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
            break;
            //Construction d'une route
            case Map::ROAD:
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
            break;
            default:
                //On ne fait rien
            break;
        }

        return true;
    }
    /**
      * Fait travailler une entité
      * @return true si réussi, false si impossible
      */
    bool Game::work(qint32 entityId)
    {
        return _workHandler->work(entityId);
    }
    /**
      * Fait attaquer une entité
      */
    bool Game::attack(qint32 entityId, qint32 x, qint32 y)
    {
        return false;
    }
}

