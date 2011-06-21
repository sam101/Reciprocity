#ifndef VIEWER_VIEWERITEM_H
#define VIEWER_VIEWERITEM_H
#include <QtGui/QGraphicsItem>
#include <World/World.h>
namespace Viewer
{
    /**
      * Objet gérant l'affichage du monde
      * @brief Gère l'affichage du monde
      * @author Sam101
      */
    class ViewerItem : public QGraphicsItem
    {
        protected:
            /**
              * Pointeur vers l'objet de monde
              */
            World::World *_world;
            /**
              * Position X de la caméra
              */
            qint32 _xCamera;
            /**
              * Position Y de la caméra
              */
            qint32 _yCamera;
            /**
              * Taille de la caméra
              */
            QRectF _size;
        public:
            /**
              * Constructeur
              */
            ViewerItem(World::World *world);
            /**
              * Renvoie le boundingRect de l'objet
              */
            virtual QRectF boundingRect() const;
            /**
              * Répaint l'objet.
              */
            virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };
}
#endif //VIEWER_VIEWERITEM_H_
