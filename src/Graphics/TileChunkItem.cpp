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
        _tiles.append(Provider::getTile("oasis").toImage());
        _tiles.append(Provider::getTile("iceberg").toImage());
        _tiles.append(Provider::getTile("volcano").toImage());

        //On définit la position
        int x,y;
        if (_chunk->getX() < 0)
        {
            _xChunk = (_chunk->getX() - Config::Config::CHUNK_SIZE + 1);
            x = _xChunk * Config::Config::TILE_SIZE;
        }
        else
        {
            _xChunk = _chunk->getX();
            x = _chunk->getX() * Config::Config::TILE_SIZE;
        }
        if (_chunk->getY() < 0)
        {
            _yChunk = _chunk->getY() - Config::Config::CHUNK_SIZE + 1;
            y = (_yChunk + 1) * Config::Config::TILE_SIZE;
        }
        else
        {
            _yChunk = _chunk->getY();
            y = (_yChunk + 1) *  Config::Config::TILE_SIZE;
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
        for (int i = _xChunk; i < _xChunk + Config::Config::TILE_SIZE; i++)
        {
            for (int j = _yChunk; j < _yChunk + Config::Config::TILE_SIZE; j++)
            {
                current = _chunk->getTile(i,j).getType();
                painter->drawImage(QPoint( (i - _xChunk) * Config::Config::TILE_SIZE,(j - _yChunk) * Config::Config::TILE_SIZE),_tiles[current]);
            }
        }
    }

}
