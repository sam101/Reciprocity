#include <Game/Game.h>
#include <QtCore/QDebug>
#include <Config/Config.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Game
{
    /**
      * Constructeur
      */
    Game::Game() :
    _world(NULL),
    _hasBegun(false)
    {
        //On alloue l'objet de monde
        _world = new World::World;
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
        }
        return c;
    }
    /**
      * Renvoie les entités d'un joueur
      */
    QList<Map::Entity*> Game::getPlayerEntities(Player *player)
    {
        //TODO: Ajouter un cache
        QList<Map::Entity*> l;
        for (qint32 i = 0; i < player->getEntities().size(); i++)
        {
            l << _world->getEntity(player->getEntities()[i]);
        }
        return l;
    }
    /**
      * Commence la partie
      */
    void Game::beginGame()
    {
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
        if ((x + y) > Config::Config::ENTITY_MOVE)
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
        //On propage la demande de nouveau tour dans le monde.
        _world->newTurn();
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
        //On trouve les coordonnées de départ.
        //TODO: Vérifier qu'il y'a personne sur le chunk.
        //TODO: Vérifier que les entités ne finissent pas dans l'eau
        xBase = Random::next(-100,100);
        yBase = Random::next(-100,100);
        //On ajoute 8 entitées au joueur
        for (int i = 0; i < Config::Config::NB_ENTITIES; i++)
        {
            //On définit la position de l'entité
            qint32 xEntity = xBase + Random::next(-Config::Config::ENTITY_ZONE,Config::Config::ENTITY_ZONE);
            qint32 yEntity = yBase + Random::next(-Config::Config::ENTITY_ZONE,Config::Config::ENTITY_ZONE);
            //On construit l'entité
            Map::Entity entity(xEntity,yEntity,player->getId());
            //On lui ajoute les ressources de base
            entity.addResource(Map::FOOD,Config::Config::FOOD_ENTITY);
            entity.addResource(Map::WOOD,Config::Config::WOOD_ENTITY);
            //On l'ajoute au monde
            addEntity(entity,xEntity,yEntity);
        }
    }
}
