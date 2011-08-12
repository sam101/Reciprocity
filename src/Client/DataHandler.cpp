#include <Client/DataHandler.h>
#include <QtCore/QDebug>
namespace Client
{
    /**
      * Constructeur
      */
    DataHandler::DataHandler()
    {

    }
    /**
      * Destructeur
      */
    DataHandler::~DataHandler()
    {
        //On détruit tout les chunks
        QMapIterator<Coordinate, Chunk::Chunk*> it(_chunks);
        while (it.hasNext())
        {
            delete it.next().value();
        }
        //On détruit toutes les entités
        QMapIterator<qint32, Map::Entity*> itE(_entities);
        while (itE.hasNext())
        {
            delete itE.next().value();
        }
    }
    /**
      * Renvoie les coordonnées X d'un chunk en fonction d'une tile
      */
    qint32 DataHandler::getXChunk(qint32 x) const
    {
        if (x < 0)
        {
            return x / Config::Config::CHUNK_SIZE - 1;
        }
        else
        {
            return x / Config::Config::CHUNK_SIZE + 1;
        }
    }
    /**
      * Renvoie les coordonnées Y d'un chunk en fonction d'une tile
      */
    qint32 DataHandler::getYChunk(qint32 y) const
    {
        if (y < 0)
        {
            return y / Config::Config::CHUNK_SIZE - 1;
        }
        else
        {
            return y / Config::Config::CHUNK_SIZE + 1;
        }
    }

    /**
      * Ajoute/Met à jour un chunk
      */
    void DataHandler::addChunk(const Chunk::Chunk &chunk)
    {
        //On supprime le chunk si il existait déjà
        if (_chunks.contains(Coordinate(getXChunk(chunk.getX()),getYChunk(chunk.getY()))))
        {
            delete _chunks[Coordinate(getXChunk(chunk.getX()),getYChunk(chunk.getY()))];
            _chunks.remove(Coordinate(getXChunk(chunk.getX()),getYChunk(chunk.getY()) ));
            _chunks[Coordinate(getXChunk(chunk.getX()),getYChunk(chunk.getY()))] = new Chunk::Chunk(chunk);
            emit chunkUpdated(_chunks[Coordinate(getXChunk(chunk.getX()) ,getYChunk(chunk.getY()))]);
            return;
        }
        //On ajoute le chunk.
        _chunks[Coordinate(getXChunk(chunk.getX()) ,getYChunk(chunk.getY()))] = new Chunk::Chunk(chunk);
        emit chunkAdded(_chunks[Coordinate(getXChunk(chunk.getX()),getYChunk(chunk.getY()))]);
    }
    /**
      * Renvoie un chunk
      */
    Chunk::Chunk* DataHandler::getChunk(qint32 x, qint32 y)
    {
        return _chunks[Coordinate(x,y)];
    }
    /**
      * Ajoute/met à jour une entité
      */
    void DataHandler::addEntity(const Map::Entity &entity)
    {
        if (_entities.contains(entity.getId()))
        {
            delete _entities[entity.getId()];
            _entities[entity.getId()] = new Map::Entity(entity);
            emit entityUpdated(_entities[entity.getId()]);
            return;
        }
        _entities[entity.getId()] = new Map::Entity(entity);
        emit entityAdded(_entities[entity.getId()]);
    }
    /**
      * Renvoie une entité
      */
    Map::Entity* DataHandler::getEntity(qint32 id)
    {
        if (!_entities.contains(id))
        {
            return NULL;
        }
        return _entities[id];
    }
    /**
      * Renvoie la liste des joueurs présents
      */
    QList<QPair<QString,bool> >& DataHandler::getPlayers()
    {
        return _players;
    }
    /**
      * Renvoie la liste des joueurs présents
      * Surchargé constant
      */
    const QList<QPair<QString,bool> >& DataHandler::getPlayers() const
    {
        return _players;
    }
    /**
      * Renvoie une tile en fonction du chunk, ou NULL
      * si elle n'est pas présente
      */
    Map::Tile* DataHandler::getTile(qint32 x, qint32 y)
    {
        Chunk::Chunk *c;
        if (x < 0)
        {
            if (y < 0)
            {
                c = getChunk(x / Config::Config::CHUNK_SIZE - 1,y / Config::Config::CHUNK_SIZE - 1);
            }
            else
            {
                c = getChunk(x / Config::Config::CHUNK_SIZE - 1,y / Config::Config::CHUNK_SIZE + 1);
            }
        }
        else
        {
            if (y < 0)
            {
                c = getChunk(x / Config::Config::CHUNK_SIZE + 1,y / Config::Config::CHUNK_SIZE - 1);
            }
            else
            {
                c = getChunk(x / Config::Config::CHUNK_SIZE + 1,y / Config::Config::CHUNK_SIZE + 1);
            }
        }
        //Si le chunk existe pas, on renvoie NULL
        if (c == NULL)
        {
            return NULL;
        }
        //Sinon, on renvoie la tile
        return &c->getTile(x,y);
    }
}
