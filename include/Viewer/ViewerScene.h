#ifndef VIEWER_VIEWERSCENE_H
#define VIEWER_VIEWERSCENE_H
#include <QtCore/QMap>
#include <QtCore/QPair>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QGraphicsScene>

#include <Graphics/TileChunkItem.h>
#include <World/World.h>
namespace Viewer
{
    /**
      * Scène gérant l'affichage d'un monde
      * @brief Gère l'affichage d'un monde
      * @author Sam101
      */
    class ViewerScene : public QGraphicsScene
    {
        protected:
            /**
              * Position X de la caméra
              */
            qint32 _xCamera;
            /**
              * Position Y de la caméra.
              */
            qint32 _yCamera;
            /**
              * Nombre de chunk à générer par rapport à la caméra
              */
            qint32 _view;
            /**
              * Pointeur vers l'objet de monde
              */
            World::World *_world;
            /**
              * Liste des chunk de la scène
              */
            QMap< QPair<qint32,qint32> ,Graphics::TileChunkItem* > _chunks;
        public:
            /**
              * Constructeur
              */
            ViewerScene(World::World *world, qint32 view = 2);
            /**
              * Ajoute un chunk à la liste des chunk de la scène
              */
            void addChunk(qint32 xChunk, qint32 yChunk);
            /**
              * Appelé à l'appui sur une touche.
              * Bouge la caméra.
              */
            void keyPressEvent(QKeyEvent *event);
    };
}
#endif // VIEWERSCENE_H
