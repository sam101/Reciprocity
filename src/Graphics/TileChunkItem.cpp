#include <Graphics/TileChunkItem.h>
#include <Config/Config.h>
namespace Graphics
{
    /**
      * Constructeur
      */
    TileChunkItem::TileChunkItem(Chunk::Chunk *chunk) :
    _chunk(chunk)
    {
        _boundingRect = QRectF(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
    }
    /**
      * Renvoie le boundingRect de l'item.
      */
    QRectF TileChunkItem::boundingRect() const
    {
        return _boundingRect;
    }
}
