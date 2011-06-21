#include <Viewer/ViewerItem.h>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerItem::ViewerItem(World::World *world) :
    _world(world),
    _xCamera(0),
    _yCamera(0)
    {

    }
    /**
      * Renvoie le boundingRect de l'objet
      */
    QRectF ViewerItem::boundingRect() const
    {
        return QRectF;
    }
    /**
      * Repaint l'objet
      */
    void ViewerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {

    }
}
