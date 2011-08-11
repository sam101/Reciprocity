#include <Client/DataHandler.h>
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
      * Ajoute/Met à jour un chunk
      */
    void DataHandler::addChunk(const Chunk::Chunk &chunk)
    {
        //On supprime le chunk si il existait déjà
        if (_chunks.contains(Coordinate(chunk.getX(),chunk.getY())))
        {
            delete _chunks[Coordinate(chunk.getX(),chunk.getY())];
            _chunks.remove(Coordinate(chunk.getX(),chunk.getY()));
        }
        //On ajoute le chunk.
        _chunks[Coordinate(chunk.getX(),chunk.getY())] = new Chunk::Chunk(chunk);
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
        }
        _entities[entity.getId()] = new Map::Entity(entity);
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
}
