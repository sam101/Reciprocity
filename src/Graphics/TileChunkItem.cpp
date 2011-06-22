#include <Graphics/TileChunkItem.h>
#include <Graphics/Provider.h>
#include <Config/Config.h>

#include <QtCore/QDebug>
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
        //On définit la position.
        int x,y;
        if (_chunk->getX() < 0)
        {
            x = (_chunk->getX() - Config::Config::CHUNK_SIZE + 1) * Config::Config::TILE_SIZE;
        }
        else
        {
            x = _chunk->getX() * Config::Config::TILE_SIZE;
        }
        if (_chunk->getY() < 0)
        {
            y = (_chunk->getY() - Config::Config::CHUNK_SIZE + 1) * Config::Config::TILE_SIZE;
        }
        else
        {
            y = _chunk->getY() *  Config::Config::TILE_SIZE;
        }
        setPos(x,y);
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
                current = _chunk->getTileAbs(j,i).getType();
                painter->drawPixmap(QPoint( (j) * Config::Config::TILE_SIZE,(i) * Config::Config::TILE_SIZE),_tiles[current]);
            }
        }
    }

}
