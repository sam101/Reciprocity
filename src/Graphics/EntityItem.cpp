#include <Graphics/EntityItem.h>
#include <Graphics/Provider.h>
#include <QtGui/QPainter>
#include <QtCore/QDebug>
namespace Graphics
{
    /**
      * Constructeur
      */
    EntityItem::EntityItem(Map::Entity *entity) :
    _entity(entity)
    {
        setZValue(42);
        //On recupère le QImage
        _image = Provider::getEntityI("entity");
        //On construit le boundingRect
        _boundingRect = QRectF(0,0,Config::Config::TILE_SIZE,Config::Config::TILE_SIZE);
        //On met à jour les coordonnées
        _x = entity->getX() * Config::Config::TILE_SIZE;
        _y = entity->getY() * Config::Config::TILE_SIZE;
        setPos(_x,_y);
    }
    /**
      * Renvoie le boundingRect
      */
    QRectF EntityItem::boundingRect() const
    {
        return _boundingRect;
    }
    /**
      * Met à jour l'entité
      */
    void EntityItem::updateEntity(Map::Entity *entity)
    {
        _entity = entity;
        _x = entity->getX() * Config::Config::TILE_SIZE;
        _y = entity->getY() * Config::Config::TILE_SIZE;
        setPos(_x,_y);
    }

    /**
      * Ré-affiche l'entité
      */
    void EntityItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        Q_UNUSED(option)
        painter->drawImage(0,0,_image);
    }
}
