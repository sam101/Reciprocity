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
            /**
              * Liste des joueurs présents
              */
            QList<QPair<QString,bool> > _players;
        public:
            /**
              * Constructeur
              */
            DataHandler();
            /**
              * Destructeur
              */
            virtual ~DataHandler();
       public slots:
            /**
              * Ajoute/Met à jour un chunk
              */
            void addChunk(Chunk::Chunk *chunk);
            /**
              * Ajoute/met à jour une entité
              */
            void addEntity(Map::Entity *entity);
        public:
            /**
              * Renvoie une entité
              */
            Map::Entity* getEntity(qint32 id);
            /**
              * Renvoie un chunk
              */
            Chunk::Chunk* getChunk(qint32 x, qint32 y);
            /**
              * Renvoie la liste des joueurs présents
              */
            QList<QPair<QString,bool> >& getPlayers();
            /**
              * Renvoie la liste des joueurs présents
              * Surchargé constant
              */
            const QList<QPair<QString,bool> >& getPlayers() const;

    };
}
#endif //CLIENT_DATAHANDLER_H
