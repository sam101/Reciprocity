#include <GUI/GameScene.h>
#include <Config/Config.h>
namespace GUI
{
    /**
      * Constructeur
      */
    GameScene::GameScene() :
    _dataHandler(NULL)
    {
        //On gère la caméra
        setSceneRect(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2);
    }
    /**
      * Ajoute/met à jour un chunk
      */
    void GameScene::addChunk(Chunk::Chunk *chunk)
    {
        if (_tiles.contains(Coordinate(chunk->getX(),chunk->getY())))
        {
            _tiles[Coordinate(chunk->getX(),chunk->getY())]->setChunk(chunk);
            _buildings[Coordinate(chunk->getX(),chunk->getY())]->setChunk(chunk);
        }
        //On ajoute le TileChunkItem
        TileChunkItem *t = new TileChunkItem(chunk);
        _tiles[Coordinate(chunk->getX(),chunk->getY())] = t;
        addItem(t);
        //On ajoute le BuildingChunkItem
        BuildingChunkItem *b = new BuildingChunkItem(chunk);
        _buildings[Coordinate(chunk->getX(),chunk->getY())] = b;
    }
}
