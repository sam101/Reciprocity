#include <Graphics/BuildingChunkItem.h>
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
        //TODO
        //On définit la position
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
      * Repaint l'objet
      */
    void BuildingChunkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {

    }
}
