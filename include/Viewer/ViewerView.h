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
        Q_OBJECT
        protected:
            /**
              * Pointeur vers la scène actuelle
              */
            ViewerScene *_scene;
            /**
              * Pointeur vers le monde actuel
              */
            World::World *_world;
            /**
              * Zoom actuel
              */
            qreal _zoom;
        public:
            /**
              * Constructeur
              */
            ViewerView();
            /**
              * Destructeur
              */
            virtual ~ViewerView();
       public slots:
            /**
              * Change le zoom actuel
              */
            void setZoom(qreal zoom);
            /**
              * Remet à zéro le monde.
              */
            void newWorld();
            /**
              * Charge un monde
              */
            void loadWorld(QString path);
            /**
              * Sauvegarde le monde actuel
              */
            void saveWorld(QString path);

    };
}
#endif //VIEWER_VIEWERVIEW_H
