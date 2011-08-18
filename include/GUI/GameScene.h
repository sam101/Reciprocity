#ifndef GUI_GAMESCENE_H
#define GUI_GAMESCENE_H
#include <Client/DataHandler.h>
#include <Graphics/BuildingChunkItem.h>
#include <Graphics/EntityItem.h>
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
            /**
              * Liste des entités affichées
              */
            QMap<qint32,EntityItem*> _entities;
            /**
              * Position X de la caméra
              */
            qint32 _xCamera;
            /**
              * Position Y de la caméra
              */
            qint32 _yCamera;
            /**
              * Position X de la tile selectionnée
              */
            qint32 _tileX;
            /**
              * Position Y de la tile selectionnée
              */
            qint32 _tileY;
            /**
              * Indique si une entité est actuellement selectionnée
              */
            bool _entitySelected;
            /**
              * Appelé à l'appui sur une touche.
              * Bouge la caméra.
              */
            void keyPressEvent(QKeyEvent *event);
            /**
              * Appelé au déplacement de la souris
              */
            void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        public:
            /**
              * Constructeur
              */
            GameScene();
            /**
              * Change l'état si une entité est selectionnée ou non
              */
            void setEntitySelected(bool entitySelected);
        public slots:
            /**
              * Ajoute/met à jour un chunk
              */
            void addChunk(Chunk::Chunk *chunk);
            /**
              * Ajoute une entité
              */
            void addEntity(Map::Entity *entity);
            /**
              * Met à jour une entité
              */
            void updateEntity(Map::Entity *entity);
        signals:
            /**
              * Envoyé quand une tile est selectionnée
              */
            void tileSelected(qint32 x, qint32 y);
            /**
              * Envoyé quand une demande de déplacement a été envoyée
              */
            void moveRequested(qint32 x, qint32 y);
    };
}
#endif //GUI_GAMESCENE_H
