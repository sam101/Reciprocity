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
        //TODO: Detruire tout les chunk et toutes les entités.
    }
    /**
      * Ajoute/Met à jour un chunk
      */
    void DataHandler::addChunk(Chunk::Chunk *chunk)
    {
        //On supprime le chunk si il existait déjà
        if (_chunks.contains(Coordinate(chunk->getX(),chunk->getY())))
        {
            delete _chunks[Coordinate(chunk->getX(),chunk->getY())];
            _chunks.remove(Coordinate(chunk->getX(),chunk->getY()));
        }
        //On ajoute le chunk.
        _chunks[Coordinate(chunk->getX(),chunk->getY())] = chunk;
    }
    /**
      * Renvoie un chunk
      */
    Chunk::Chunk* DataHandler::getChunk(qint32 x, qint32 y)
    {
        return _chunks[Coordinate(x,y)];
    }
}
