#include <World/World.h>
#include <Config/BaseConfig.h>
#include <Config/Config.h>
#include <Config/EntityConfig.h>
#include <Config/LifeConfig.h>
#include <Config/OutputConfig.h>
#include <QDebug>
using namespace Config;
namespace World
{
    /**
      * Constructeur
      */
    World::World() :
    _generator(NULL)
    {
        //On donne la taille de départ du tableau
        _chunkTL.resize(1);
        _chunkTR.resize(1);
        _chunkBL.resize(1);
        _chunkBR.resize(1);
        //On alloue le générateur
        _generator = new WorldGenerator(this);

    }
    /**
      * Destructeur.
      * Détruit toutes les entitées présentes
      * dans le monde
      */
    World::~World()
    {
        if (_generator != NULL)
        {
            delete _generator;
        }
        /*
         * On détruit les tableau de chunk
         */
        for (int i = 0; i < _chunkTL.size(); i++)
        {
            for (int j = 0; j < _chunkTL[i].size(); j++)
            {
                delete _chunkTL[i][j];
            }
        }
        for (int i = 0; i < _chunkTR.size(); i++)
        {
            for (int j = 0; j < _chunkTR[i].size(); j++)
            {
                delete _chunkTR[i][j];
            }
        }
        for (int i = 0; i < _chunkBL.size(); i++)
        {
            for (int j = 0; j < _chunkBL[i].size(); j++)
            {
                delete _chunkBL[i][j];
            }
        }
        for (int i = 0; i < _chunkBR.size(); i++)
        {
            for (int j = 0; j < _chunkBR[i].size(); j++)
            {
                delete _chunkBR[i][j];
            }
        }
    }
    /**
      * Renvoie les coordonnées X d'un chunk en fonction d'une tile
      */
    qint32 World::getXChunk(qint32 x) const
    {
        if (x < 0)
        {
            return x / BaseConfig::CHUNK_SIZE - 1;
        }
        else
        {
            return x / BaseConfig::CHUNK_SIZE + 1;
        }
    }
    /**
      * Renvoie les coordonnées Y d'un chunk en fonction d'une tile
      */
    qint32 World::getYChunk(qint32 y) const
    {
        if (y < 0)
        {
            return y / BaseConfig::CHUNK_SIZE - 1;
        }
        else
        {
            return y / BaseConfig::CHUNK_SIZE + 1;
        }
    }
    /**
      * Renvoie un chunk du monde. Les coordonnées
      * sont par chunk (et non par tile).
      * Cette méthode n'est pas const car il y'a possibilité
      * de génération d'un nouveau chunk à l'appel.
      */
    Chunk::Chunk* World::getChunk(int x, int y)
    {
        if (x == 0 || y == 0)
        {
            return NULL;
        }
        //On gère les cas positifs/négatifs.
        if (x < 0)
        {
            if (y < 0)
            {
                //On genère les chunk qui n'existent pas.
                if (abs(y) >= _chunkTL.size() || abs(x) >= _chunkTL[abs(y)].size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTL[abs(y)][abs(x)];
            }
            else
            {
                if (y >= _chunkBL.size() || abs(x) >= _chunkBL[y].size())
                {
                    _generator->generate(x,y);
                }
                return _chunkBL[y][abs(x)];
            }
        }
        else
        {
            if (y < 0)
            {
                //On genère les chunk si il y'a besoin
                if (abs(y) >= _chunkTR.size() || x >= _chunkTR[abs(y)].size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTR[abs(y)][x];
            }
            else
            {
                if (y >= _chunkBR.size() || x >= _chunkBR[y].size())
                {
                    _generator->generate(x,y);
                }
                return _chunkBR[y][x];
            }
        }
    }
    /**
      * Renvoie une tile du monde.
      * N'est pas const car possibiliré de génération d'un chunk.
      */
    Map::Tile& World::getTile(int x, int y)
    {
        return getChunk(getXChunk(x),getYChunk(y))->getTile(x,y);

    }
    /**
      * Renvoie un batiment du monde
      * Possibilité de génération du monde, donc non const
      */
    Map::Building& World::getBuilding(int x, int y)
    {
        return getChunk(getXChunk(x),getYChunk(y))->getBuilding(x,y);
    }

    /**
      * Renvoie le chunk associé à la position
      */
    Chunk::Chunk* World::getChunkByTile(int x, int y)
    {
        return getChunk(getXChunk(x),getYChunk(y));
    }
    /**
      * Ajoute une entité et renvoie son id.
      */
    qint32 World::addEntity(const Map::Entity &entity, qint32 x, qint32 y)
    {
        //On l'ajoute au tableau d'entités.
        _entities.append(new Map::Entity(entity));
        _entities.last()->setXY(x,y);
        //On recupère son id
        qint32 id = _entities.size() - 1;
        _entities.last()->setId(id);
        //On l'ajoute au bon chunk
        getChunkByTile(x,y)->addEntity(id);
        //On renvoie son id
        return id;
    }
    /**
      * Commence la construction d'un batiment
      * @return Si la construction à réussi (Non-présence d'un batiment sur la case)
      */
    bool World::addBuilding(qint32 x, qint32 y, Map::BuildingType type, qint32 owner)
    {
        //On vérifie qu'il y'a pas déjà un batiment
        if (getBuilding(x,y).getType() != Map::NONE)
        {
            return false;
        }
        //On construit le batiment.
        switch (type)
        {
            case Map::HOUSE:
                //On vérifie que on essaye pas de construire sur l'eau
                if ((getTile(x,y).getFlags() & Map::Tile::PASSABLE) == 0)
                {
                    return false;
                }
                getBuilding(x,y) = Map::Building(x,y,type,1,1,LifeConfig::LIFE_HOUSE,owner);
            break;
            case Map::FARMLAND:
                //On vérifie que on peut bien construire un champ sur la tile
                if ((getTile(x,y).getFlags() & Map::Tile::FARMING_CAPABLE) == 0)
                {
                    return false;
                }
                getBuilding(x,y) = Map::Building(x,y,type,1,1,LifeConfig::LIFE_FARMLAND,owner);
            break;
            case Map::ROAD:
                //On vérifie qu'on construit pas sur l'eau
                if ((getTile(x,y).getFlags() & Map::Tile::PASSABLE) == 0)
                {
                    return false;
                }
                getBuilding(x,y) = Map::Building(x,y,type,LifeConfig::LIFE_ROAD,LifeConfig::LIFE_ROAD,owner);
            break;
            case Map::WALL:
                //On vérifie qu'on construit pas sur l'eau
                if ((getTile(x,y).getFlags() & Map::Tile::PASSABLE) == 0)
                {
                    return false;
                }
                getBuilding(x,y) = Map::Building(x,y,type,LifeConfig::LIFE_WALL,LifeConfig::LIFE_WALL,owner);

            break;
            default:
            break;
        }
        return true;

    }
    /**
      * Supprime un batiment
      */
    void World::delBuilding(qint32 x, qint32 y)
    {
        getBuilding(x,y) = Map::Building(x,y);
    }
    /**
      * Déplace une entité
      */
    void World::moveEntity(qint32 id, qint32 x, qint32 y)
    {
        //Verification de validité de l'entité
        if (id < 0 || id >= _entities.size() )
        {
            return;
        }
        //On recupère le chunk où est actuellement l'entité.
        Chunk::Chunk *current  = getChunkByTile(_entities[id]->getX(),_entities[id]->getY());
        //On recupère le prochain Chunk ou sera l'entité
        Chunk::Chunk *next = getChunkByTile(_entities[id]->getX() + x,_entities[id]->getY() + y);
        //Si les chunk sont différants, on change l'entité de chunk
        if (next != current)
        {
            current->delEntity(id);
            next->addEntity(id);
        }
        //On change la position de l'entité
        _entities[id]->move(x,y);
        //On indique que l'entité s'est déplacée.
        _entities[id]->setHasMoved();
    }
    /**
      * Supprime une entité
      */
    void World::delEntity(qint32 id)
    {
        //On vérifie la validité de l'id
        if (id < 0 || id > _entities.size() )
        {
            return;
        }
        //On la supprime du chunk
        Chunk::Chunk *chunk = getChunkByTile(_entities[id]->getX(),_entities[id]->getY());
        chunk->delEntity(id);
        //On la supprime l'entité
        _entities[id]->kill();
    }

    /**
      * Renvoie une entité en fonction de son id
      */
    Map::Entity* World::getEntity(qint32 id)
    {
        if (id < 0 || id >= _entities.size())
        {
            return NULL;
        }
        return _entities[id];
    }
    /**
      * Renvoie une entité en fonction de son id
      * Surchargé constant.
      */
    const Map::Entity* World::getEntity(qint32 id) const
    {
        if (id < 0 || id >= _entities.size())
        {
            return NULL;
        }
        return _entities.at(id);
    }
    /**
      * Renvoie la liste des joueurs voyant l'entité
      */
    QSet<qint32> World::getPlayerEntityList(qint32 id)
    {
        //TODO: Maintenir un cache
        //On vérifie l'id de l'entité
        if (id < 0 || id > _entities.size())
        {
            return QSet<qint32>();
        }
        //On déclare la liste
        QSet<qint32> list;
        //On recupère le chunk
        Chunk::Chunk *chunk = getChunkByTile(_entities[id]->getX(),_entities[id]->getY());
        //On recupère les entités du chunk
        const QSet<qint32> &entitiesOnChunk = chunk->getEntities();
        //On remplit la liste
        QSetIterator<qint32> it(entitiesOnChunk);
        while (it.hasNext())
        {
            list << _entities[it.next()]->getOwner();
        }
        //On renvoie la liste
        return list;
    }
    /**
      * Renvoie le nombre d'entités à une position donnée
      */
    qint32 World::getNbEntitiesOnTile(qint32 x, qint32 y)
    {
        qint32 nb = 0;
        QSetIterator<qint32> it(getChunkByTile(x,y)->getEntities());
        while (it.hasNext())
        {
            nb++;
            it.next();
        }
        return nb;
    }
    /**
      * Passe au tour suivant:
      *  - Remet le compteur de déplacement des entités à zéro
      *  - Termine les actions des entités
      */
    void World::newTurn()
    {
        for (int i = 0; i < _entities.size(); i++)
        {
            //On remet à zéro le compteur de déplacement
            _entities[i]->resetMove();
            //On restaure le moral si l'entité est sur une maison
            Map::Building &building = getBuilding(_entities[i]->getX(),_entities[i]->getY());
            if (building.getType() == Map::HOUSE && building.isFinished() && getNbEntitiesOnTile(_entities[i]->getX(),_entities[i]->getY()) <= EntityConfig::NB_ENTITIES_HOUSE_MAX)
            {
                _entities[i]->restoreWill(EntityConfig::WILL_HOUSE);
            }
            //Sinon, on baisse le moral de l'entité
            else
            {
                _entities[i]->delWill(EntityConfig::WILL_LOST_TURN);
            }
            //On baisse la nouriture de l'entité et sa vie si elle n'en a pas
            if (_entities[i]->getResource(Map::FOOD) < EntityConfig::ENTITY_FOOD_USED)
            {
                _entities[i]->damage(EntityConfig::LIFE_STARVING);
            }
            else
            {
                _entities[i]->delRessource(Map::FOOD,EntityConfig::ENTITY_FOOD_USED);
            }
        }
        //On propage le nouveau tour dans tout les chunks
        for (int i = 1; i < _chunkTL.size(); i++)
        {
            for (int j = 1; j < _chunkTL[i].size(); j++)
            {
                _chunkTL[i][j]->newTurn(OutputConfig::OUTPUT_TURN);
            }
        }
        for (int i = 1; i < _chunkTR.size(); i++)
        {
            for (int j = 1; j < _chunkTR[i].size(); j++)
            {
                _chunkTR[i][j]->newTurn(OutputConfig::OUTPUT_TURN);
            }
        }
        for (int i = 1; i < _chunkBL.size(); i++)
        {
            for (int j = 1; j < _chunkBL[i].size(); j++)
            {
                _chunkBL[i][j]->newTurn(OutputConfig::OUTPUT_TURN);
            }
        }
        for (int i = 1; i < _chunkBR.size(); i++)
        {
            for (int j = 1; j < _chunkBR[i].size(); j++)
            {
                _chunkBR[i][j]->newTurn(OutputConfig::OUTPUT_TURN);
            }
        }

    }

    /**
      * Stocke un monde dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const World &w)
    {
        out << World::WORLD_MAGICNUMBER;
        out << World::WORLD_VERSION;

        //On stocke la taille de chunkTL
        out << (qint32)w._chunkTL.size();
        out << (qint32)w._chunkTL[0].size();
        //On stocke les chunk de chunkTL
        for (int i = 1; i < w._chunkTL.size(); i++)
        {
            for (int j = 1; j < w._chunkTL[i].size(); i++)
            {
                out << *w._chunkTL[i][j];
            }
        }
        //On stocke la taille de chunkTR
        out << (qint32)w._chunkTR.size();
        out << (qint32)w._chunkTR[0].size();
        //On stocke les chunk de chunkTR
        for (int i = 1; i < w._chunkTR.size(); i++)
        {
            for (int j = 1; j < w._chunkTR[i].size(); i++)
            {
                out << *w._chunkTR[i][j];
            }
        }
        //On stocke la taille de chunkBL
        out << (qint32)w._chunkBL.size();
        out << (qint32)w._chunkBL[0].size();
        //On stocke les chunk de chunBLL
        for (int i = 1; i < w._chunkBL.size(); i++)
        {
            for (int j = 1; j < w._chunkBL[i].size(); i++)
            {
                out << *w._chunkBL[i][j];
            }
        }
        //On stocke la taille de chunkBR
        out << (qint32)w._chunkBR.size();
        out << (qint32)w._chunkBR[0].size();
        //On stocke les chunk de chunkBR
        for (int i = 1; i < w._chunkBR.size(); i++)
        {
            for (int j = 1; j < w._chunkBR[i].size(); i++)
            {
                out << *w._chunkBR[i][j];
            }
        }

        return out;
    }
    /**
      * Recupère un monde d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, World &w)
    {
        int width, height;
        //On vérifie le magicNumber et la version
        qint32 magicNumber, version;
        in >> magicNumber;
        in >> version;
        Q_ASSERT(magicNumber == World::WORLD_MAGICNUMBER);
        Q_ASSERT(version == World::WORLD_VERSION);

        //On recupère les données de chunkTL
        in >> height;
        in >> width;

        w._chunkTL.resize(height);
        for (int i = 1; i < height; i++)
        {
            w._chunkTL[i].resize(width);
            for (int j = 1; j < width; j++)
            {
                w._chunkTL[i][j] = new Chunk::Chunk(i,j);
                in >> *w._chunkTL[i][j];
            }
        }
        //On recupère les données de chunkTR
        in >> height;
        in >> width;

        w._chunkTL.resize(height);
        for (int i = 1; i < height; i++)
        {
            w._chunkTR[i].resize(width);
            for (int j = 1; j < width; j++)
            {
                w._chunkTR[i][j] = new Chunk::Chunk(i,j);
                in >> *w._chunkTR[i][j];
            }
        }
        //On recupère les données de chunkBL
        in >> height;
        in >> width;

        w._chunkBL.resize(height);
        for (int i = 1; i < height; i++)
        {
            w._chunkBL[i].resize(width);
            for (int j = 1; j < width; j++)
            {
                w._chunkBL[i][j] = new Chunk::Chunk(i,j);
                in >> *w._chunkBL[i][j];
            }
        }
        //On recupère les données de chunkBR
        in >> height;
        in >> width;

        w._chunkBL.resize(height);
        for (int i = 1; i < height; i++)
        {
            w._chunkBR[i].resize(width);
            for (int j = 1; j < width; j++)
            {
                w._chunkBR[i][j] = new Chunk::Chunk(i,j);
                in >> *w._chunkBR[i][j];
            }
        }

        return in;
    }

}
