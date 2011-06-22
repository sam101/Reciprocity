#ifndef GRAPHICS_TILECHUNKITEM_H
#define GRAPHICS_TILECHUNKITEM_H
#include <Chunk/Chunk.h>
#include <QtCore/QList>
#include <QtGui/QGraphicsItem>
#include <QtGui/QPixmap>
namespace Graphics
{
    /**
      * Gère l'affichage des tiles d'un chunk dans un QGraphicsItem
      * @brief Gère l'affichage des tiles d'un chunk
      * @author Sam101
      */
    class TileChunkItem : public QGraphicsItem
    {
        protected:
            /**
              * Position X du chunk
              */
            qint32 _xChunk;
            /**
              * Position Y du chunk
              */
            qint32 _yChunk;
            /**
              * Pointeur vers le Chunk duquel on doit dessiner les tiles
              */
            Chunk::Chunk *_chunk;
            /**
              * Tableau contenant les pixmap des tiles
              */
            QList<QPixmap> _tiles;
        public:
            /**
              * Constructeur
              */
            TileChunkItem(Chunk::Chunk *chunk);
    };
}
#endif //GRAPHICS_TILECHUNKITEM_H
