#ifndef VIEWER_VIEWERVIEW_H
#define VIEWER_VIEWERVIEW_H
#include <QtGui/QGraphicsView>

#include <Viewer/ViewerScene.h>
#include <World/World.h>
namespace Viewer
{
    /**
      * Vue gérant l'affichage d'un monde
      * @brief Vue gérant l'affichage d'un monde
      * @author Sam101
      */
    class ViewerView : public QGraphicsView
    {
        protected:
            /**
              * Pointeur vers la scène actuelle
              */
            ViewerScene *_scene;
            /**
              * Pointeur vers le monde actuel
              */
            World::World *_world;
        public:
            /**
              * Constructeur
              */
            ViewerView();
            /**
              * Destructeur
              */
            ~ViewerView();
    };
}
#endif //VIEWER_VIEWERVIEW_H
