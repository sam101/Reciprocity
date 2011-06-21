#ifndef VIEWER_VIEWERSCENE_H
#define VIEWER_VIEWERSCENE_H
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QGraphicsScene>
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
              * Pointeur vers l'objet de monde
              */
            World::World *_world;
        public:
        /**
          * Constructeur
          */
        ViewerScene(World::World *world);
    };
}
#endif // VIEWERSCENE_H
