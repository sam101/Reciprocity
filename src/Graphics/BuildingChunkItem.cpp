#include <Graphics/BuildingChunkItem.h>
#include <Graphics/Provider.h>
#include <QtGui/QPainter>
namespace Graphics
{
    /**
      * Constructeur
      */
    BuildingChunkItem::BuildingChunkItem(Chunk::Chunk *chunk) :
    _chunk(chunk)
    {
        //On construit le boundingRect de l'objet
        _boundingRect = QRectF(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
        //On charge le tableau des batiments
        _tiles.append(Provider::getBuilding("none").toImage());
        _tiles.append(Provider::getBuilding("house").toImage());
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
      * Renvoie le boundingRect de l'objet
      */
    QRectF BuildingChunkItem::boundingRect() const
    {
        return _boundingRect;
    }
    /**
      * Change le chunk de l'objet.
      * Part du principe qu'il est à la même position
      */
    void BuildingChunkItem::setChunk(Chunk::Chunk *chunk)
    {
        _chunk = chunk;
        update();
    }

    /**
      * Repaint l'objet
      */
    void BuildingChunkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option)
        Q_UNUSED(widget)
        qint32 current;

        for (int i = _xChunk; i < _xChunk + Config::Config::TILE_SIZE; i++)
        {
            for (int j = _yChunk; j < _yChunk + Config::Config::TILE_SIZE; j++)
            {
                current = _chunk->getBuilding(j,i).getType();
                painter->drawImage(QPoint( (j) * Config::Config::TILE_SIZE,(i) * Config::Config::TILE_SIZE),_tiles[current]);
            }
        }
    }
}
