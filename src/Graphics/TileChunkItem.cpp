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
        qDebug() << "Chunk:" << _chunk->getX() << _chunk->getY();
        //On définit le boundingRect de l'Item
        _boundingRect = QRectF(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
        //On charge le tableau de tiles.
        //TODO: Faire un truc mieux
        _tiles.append(Provider::getTile("nothing").toImage());
        _tiles.append(Provider::getTile("sea").toImage());
        _tiles.append(Provider::getTile("lowland").toImage());
        _tiles.append(Provider::getTile("forest").toImage());
        _tiles.append(Provider::getTile("lake").toImage());
        _tiles.append(Provider::getTile("river").toImage());
        _tiles.append(Provider::getTile("mountain").toImage());
        _tiles.append(Provider::getTile("beach").toImage());
        _tiles.append(Provider::getTile("swamp").toImage());
        //On définit la position
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
            y = (_chunk->getY() - Config::Config::CHUNK_SIZE + 2) * Config::Config::TILE_SIZE;
        }
        else
        {
            y = (_chunk->getY() + 1) *  Config::Config::TILE_SIZE;
        }
        qDebug() << "Pos:" << x << y;
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
      * Change le chunk de l'objet.
      * Part du principe qu'il est à la même position
      */
    void TileChunkItem::setChunk(Chunk::Chunk *chunk)
    {
        _chunk = chunk;
        update();
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
                current = _chunk->getTileAbs(i,j).getType();
                painter->drawImage(QPoint( (i) * Config::Config::TILE_SIZE,(j) * Config::Config::TILE_SIZE),_tiles[current]);
            }
        }
    }

}
