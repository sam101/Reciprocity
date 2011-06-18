#ifndef CHUNK_CHUNKTYPE_H
#define CHUNK_CHUNKTYPE_H
namespace Chunk
{
    /**
      *  Conteint les différants types de chunk
      */
    enum ChunkType
    {
        /**
          * Chunk contenant que de l'eau et de petites iles
          */
        SEA = 0,
        /**
          * Chunk contenant uniquement un monde intérieur parsemé de lacs
          */
        LAND = 1
    };

}
#endif // CHUNKTYPE_H
