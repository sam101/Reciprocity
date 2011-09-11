#ifndef WORLD_WORLD_H
#define WORLD_WORLD_H
#include <QtCore/QDataStream>
#include <QtCore/QVector>

#include <Chunk/Chunk.h>
#include <Map/Entity.h>
#include <Map/Tile.h>
#include <World/WorldGenerator.h>
namespace World
{
    /**
      * Gère le monde principal et sa génération, ainsi
      * que la présence des entités sur celui-ci.
      * @brief Gère le monde principal et sa génération.
      * @author Sam101
      */
    class World
    {
        friend class WorldGenerator;
        public:
            /**
              * Magic number de World
              */
             static const qint32 WORLD_MAGICNUMBER = 0x42424203;
             /**
               * Version de World
               */
             static const qint32 WORLD_VERSION = 1;
        protected:
            /**
              * Pointeur vers le générateur du monde
              */
            WorldGenerator *_generator;
            /**
              * Tableau des chunks en haut à gauche
              */
            QVector<QVector<Chunk::Chunk*> > _chunkTL;
            /**
              * Tableau des chunks en haut à droite
              */
            QVector<QVector<Chunk::Chunk*> > _chunkTR;
            /**
              * Tableau des chunks en bas à gauche
              */
            QVector<QVector<Chunk::Chunk*> > _chunkBL;
            /**
              * Tableau des chunks en bas à droite
              */
             QVector<QVector<Chunk::Chunk*> > _chunkBR;
             /**
               * Tableau des entités.
               */
             QList<Map::Entity*> _entities;

    public:
                /**
                  * Constructeur
                  */
                World();
                /**
                  * Destructeur.
                  * Détruit toutes les entitées présentes
                  * dans le monde
                  */
                virtual ~World();
                /**
                  * Renvoie les coordonnées X d'un chunk en fonction d'une tile
                  */
                qint32 getXChunk(qint32 x) const;
                /**
                  * Renvoie les coordonnées Y d'un chunk en fonction d'une tile
                  */
                qint32 getYChunk(qint32 y) const;
                /**
                  * Renvoie un chunk du monde. Les coordonnées
                  * sont par chunk (et non par tile).
                  * Cette méthode n'est pas const car il y'a possibilité
                  * de génération d'un nouveau chunk à l'appel.
                  */
                Chunk::Chunk* getChunk(int x, int y);
                /**
                  * Renvoie une tile du monde.
                  * N'est pas const car possibilité de génération d'un chunk.
                  */
                Map::Tile& getTile(int x, int y);
                /**
                  * Renvoie un batiment du monde
                  * Possibilité de génération du monde, donc non const
                  */
                Map::Building& getBuilding(int x, int y);
                /**
                  * Renvoie le chunk associé à la position
                  */
                Chunk::Chunk* getChunkByTile(int x, int y);
                /**
                  * Ajoute une entité et renvoie son id.
                  */
                qint32 addEntity(const Map::Entity &entity, qint32 x, qint32 y);
                /**
                  * Commence la construction d'un batiment
                  * @return Si la construction à réussi (Non-présence d'un batiment sur la case)
                  */
                bool addBuilding(qint32 x, qint32 y, Map::BuildingType type);
                /**
                  * Déplace une entité
                  */
                void moveEntity(qint32 id, qint32 x, qint32 y);
                /**
                  * Renvoie une entité en fonction de son id
                  */
                Map::Entity* getEntity(qint32 id);
                /**
                  * Renvoie une entité en fonction de son id
                  * Surchargé constant
                  */
                const Map::Entity* getEntity(qint32 id) const;
                /**
                  * Passe au tour suivant:
                  *  - Remet le compteur de déplacement des entités à zéro
                  *  - Termine les actions des entités
                  */
                void newTurn();
                /**
                  * Stocke un monde dans un QDataStream
                  */
                friend QDataStream& operator<<(QDataStream &out, const World &w);
                /**
                  * Recupère un monde d'un QDataStream
                  */
                friend QDataStream& operator>>(QDataStream &in, World &w);
    };   
}
#endif //WORLD_WORLD_H
