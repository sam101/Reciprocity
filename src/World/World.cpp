#include <World/World.h>
#include <Config/Config.h>
#include <QDebug>
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
         * On détruit le tableau de chunk
         */
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
                //On geneère les chunk qui n'existent pas.
                if (abs(x) >= _chunkTL[0].size() || abs(y) >= _chunkTL.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTL[abs(y)][abs(x)];
            }
            else
            {
                if (abs(x) >= _chunkBL[0].size() || y >= _chunkBL.size())
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
                if (x >= _chunkTR[0].size() || abs(y) >= _chunkTR.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTR[abs(y)][x];
            }
            else
            {
                if (x >= _chunkBR[0].size() || y >= _chunkBR.size())
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
        if (x < 0)
        {
            if (y < 0)
            {
                return getChunk(x / Config::Config::CHUNK_SIZE - 1,y / Config::Config::CHUNK_SIZE - 1)->getTile(x,y);
            }
            else
            {
                return getChunk(x / Config::Config::CHUNK_SIZE - 1,y / Config::Config::CHUNK_SIZE + 1)->getTile(x,y);
            }
        }
        else
        {
            if (y < 0)
            {
                return getChunk(x / Config::Config::CHUNK_SIZE + 1,y / Config::Config::CHUNK_SIZE - 1)->getTile(x,y);
            }
            else
            {
                return getChunk(x / Config::Config::CHUNK_SIZE + 1,y / Config::Config::CHUNK_SIZE + 1)->getTile(x,y);
            }
        }
    }
    /**
      * Ajoute une entité et renvoie son id.
      */
    qint32 World::addEntity(Map::Entity entity, qint32 x, qint32 y)
    {
        //On l'ajoute au tableau d'entités.
        _entities.append(new Map::Entity(entity));
        _entities.last()->setXY(x,y);
        //On l'ajoute au bon chunk
        //TODO
        //On renvoie son id
        return _entities.size() - 1;
    }
    /**
      * Renvoie une entité en fonction de son id
      */
    Map::Entity* World::getEntity(qint32 id)
    {
        return _entities[id];
    }
    /**
      * Renvoie une entité en fonction de son id
      * Surchargé constant.
      */
    const Map::Entity* World::getEntity(qint32 id) const
    {
        return _entities.at(id);
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
        for (int i = 0; i < w._chunkTL.size(); i++)
        {
            for (int j = 0; j < w._chunkTL[i].size(); i++)
            {
                out << *w._chunkTL[i][j];
            }
        }
        //On stocke la taille de chunkTR
        out << (qint32)w._chunkTR.size();
        out << (qint32)w._chunkTR[0].size();
        //On stocke les chunk de chunkTR
        for (int i = 0; i < w._chunkTR.size(); i++)
        {
            for (int j = 0; j < w._chunkTR[i].size(); i++)
            {
                out << *w._chunkTR[i][j];
            }
        }
        //On stocke la taille de chunkBL
        out << (qint32)w._chunkBL.size();
        out << (qint32)w._chunkBL[0].size();
        //On stocke les chunk de chunkTL
        for (int i = 0; i < w._chunkBL.size(); i++)
        {
            for (int j = 0; j < w._chunkBL[i].size(); i++)
            {
                out << *w._chunkBL[i][j];
            }
        }
        //On stocke la taille de chunkBR
        out << (qint32)w._chunkBR.size();
        out << (qint32)w._chunkBR[0].size();
        //On stocke les chunk de chunkBR
        for (int i = 0; i < w._chunkBR.size(); i++)
        {
            for (int j = 0; j < w._chunkBR[i].size(); i++)
            {
                out << *w._chunkBR[i][j];
            }
        }

        return out;
    }
}
