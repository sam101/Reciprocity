#include <Graphics/EntityItem.h>
#include <Graphics/Provider.h>
#include <QtGui/QPainter>
#include <QtCore/QDebug>
#include <Config/BaseConfig.h>
using namespace Config;
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
        _imageMoved = Provider::getEntityI("entityMoved");
        //On construit le boundingRect
        _boundingRect = QRectF(0,0,BaseConfig::TILE_SIZE,BaseConfig::TILE_SIZE);
        //On met à jour les coordonnées
        _x = entity->getX() * BaseConfig::TILE_SIZE;
        _y = (entity->getY() + 1) * BaseConfig::TILE_SIZE;
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
        _x = entity->getX() * BaseConfig::TILE_SIZE;
        _y = (entity->getY() + 1) * BaseConfig::TILE_SIZE;
        setPos(_x,_y);
        update(_boundingRect);
    }

    /**
      * Ré-affiche l'entité
      */
    void EntityItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(widget)
        Q_UNUSED(option)
        if (_entity && _entity->hasMoved())
        {
            painter->drawImage(0,0,_imageMoved);
        }
        else
        {
            painter->drawImage(0,0,_image);
        }
    }

}
