#ifndef GRAPHICS_ENTITYITEM_H
#define GRAPHICS_ENTITYITEM_H
#include <Map/Entity.h>
#include <QtGui/QGraphicsItem>
#include <QtGui/QImage>
namespace Graphics
{
    /**
      * Gère l'affichage d'une enttié
      * @brief Gère l'affichage d'une entité
      * @author Sam101
      */
    class EntityItem : public QGraphicsItem
    {
        protected:
            /**
              * Pointeur vers l'Entité
              */
            Map::Entity *_entity;
            /**
              * BoundingRect de l'EntityItem
              */
            QRectF _boundingRect;
            /**
              * Pixmap de l'EntityItem
              */
            QImage _image;
            /**
              * Pixmap de l'EntityItem déplacé
              */
            QImage _imageMoved;
            /**
              * Position X de l'entité
              */
            qint32 _x;
            /**
              * Position Y de l'entité
              */
            qint32 _y;
        public:
            /**
              * Constructeur
              */
            EntityItem(Map::Entity *entity);
            /**
              * Renvoie le boundingRect
              */
            QRectF boundingRect() const;
            /**
              * Met à jour l'entité
              */
            void updateEntity(Map::Entity *entity);
            /**
              * Ré-affiche l'entité
              */
            void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    };
}
#endif //GRAPHICS_ENTITYITEM_H
