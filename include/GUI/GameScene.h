#ifndef GUI_GAMESCENE_H
#define GUI_GAMESCENE_H
#include <Client/DataHandler.h>
#include <Graphics/BuildingChunkItem.h>
#include <Graphics/TileChunkItem.h>

#include <QtCore/QMap>
#include <QtGui/QGraphicsScene>
using namespace Graphics;
namespace GUI
{
    /**
      * Gère la scène du jeu, gérant les divers objets
      * présents dans la scène.
      * @brief Gère la scène du jeu
      * @author Sam101
      */
    class GameScene: public QGraphicsScene
    {
        Q_OBJECT
        public:
            typedef QPair<qint32, qint32> Coordinate;
        protected:
            /**
              * Pointeur vers le DataHandler
              */
            Client::DataHandler *_dataHandler;
            /**
              * Liste des chunks affichés en temps que tile.
              */
            QMap<Coordinate, TileChunkItem* > _tiles;
            /**
              * Liste des batiment dans des chunks affichés
              */
            QMap<Coordinate, BuildingChunkItem* > _buildings;
        public:
            /**
              * Constructeur
              */
            GameScene();
        public slots:
            /**
              * Ajoute/met à jour un chunk
              */
            void addChunk(Chunk::Chunk *chunk);
    };
}
#endif //GUI_GAMESCENE_H
