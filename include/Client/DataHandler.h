#ifndef CLIENT_DATAHANDLER_H
#define CLIENT_DATAHANDLER_H
#include <Chunk/Chunk.h>
#include <Map/Entity.h>

#include <QtCore/QMap>
#include <QtCore/QObject>
#include <QtCore/QPair>
namespace Client
{
    /**
      * Gère les données à disposition du client
      * @brief Gère les données à disposition du client
      * @author Sam101
      */
    class DataHandler : public QObject
    {
        Q_OBJECT
    public:
            /**
              * Typedef
              */
            typedef QPair<qint32,qint32> Coordinate;
        protected:
            /**
              * Map des chunk visibles par le client
              */
            QMap<Coordinate , Chunk::Chunk* > _chunks;
            /**
              * Entitées visibles par le joueur
              */
            QMap<qint32,Map::Entity*> _entities;
       public:
            /**
              * Constructeur
              */
            DataHandler();
            /**
              * Destructeur
              */
            virtual ~DataHandler();
            /**
              * Ajoute/Met à jour un chunk
              */
            void addChunk(Chunk::Chunk *chunk);
            /**
              * Renvoie un chunk
              */
            Chunk::Chunk* getChunk(qint32 x, qint32 y);
            /**
              * Ajoute/met à jour une entité
              */
            void addEntity(Map::Entity *entity);
            /**
              * Renvoie une entité
              */
            Map::Entity* getEntity(qint32 id);

    };
}
#endif //CLIENT_DATAHANDLER_H
