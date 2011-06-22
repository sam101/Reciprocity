#include <Graphics/TileChunkItem.h>
#include <Graphics/Provider.h>
#include <Config/Config.h>

#include <QtGui/QPainter>
namespace Graphics
{
    /**
      * Constructeur
      */
    TileChunkItem::TileChunkItem(Chunk::Chunk *chunk) :
    _chunk(chunk)
    {
        //On définit le boundingRect de l'Item
        _boundingRect = QRectF(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
        //On charge le tableau de tiles.
        _tiles.append(Provider::getTile("nothing"));
        _tiles.append(Provider::getTile("sea"));
        _tiles.append(Provider::getTile("lowland"));
        _tiles.append(Provider::getTile("forest"));
        _tiles.append(Provider::getTile("lake"));
        _tiles.append(Provider::getTile("river"));
        _tiles.append(Provider::getTile("mountain"));
    }
    /**
      * Renvoie le boundingRect de l'item.
      */
    QRectF TileChunkItem::boundingRect() const
    {
        return _boundingRect;
    }
    /**
      * Repaint l'objet
      */
    void TileChunkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option)
        Q_UNUSED(widget)
        qint32 current;
        for (int i = 0; i < Config::Config::TILE_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::TILE_SIZE; j++)
            {
                current = _chunk->getTile(j + _chunk->getX(),i + _chunk->getY()).getType();
                painter->drawPixmap(QPoint(j * Config::Config::TILE_SIZE, i * Config::Config::TILE_SIZE),_tiles[current]);
            }
        }
    }

}
