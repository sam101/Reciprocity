#include <GUI/GameScene.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
#include <QtGui/QKeyEvent>
namespace GUI
{
    /**
      * Constructeur
      */
    GameScene::GameScene() :
    _dataHandler(NULL),
    _xCamera(0),
    _yCamera(0)
    {
        setBackgroundBrush(Qt::black);
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
        addItem(b);
        //On change la caméra
        _xCamera = chunk->getX();
        _yCamera = chunk->getY();
        setSceneRect(_xCamera * Config::Config::TILE_SIZE,_yCamera * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2);

    }
    /**
      * Appelé à l'appui sur une touche.
      * Bouge la caméra.
      */
    void GameScene::keyPressEvent(QKeyEvent *event)
    {
        //On gère selon la touche
        switch (event->key())
        {
            case Qt::Key_Up:
                _yCamera--;
            break;
            case Qt::Key_Down:
                _yCamera++;
            break;
            case Qt::Key_Left:
                _xCamera--;
            break;
            case Qt::Key_Right:
                _xCamera++;
            break;

        }
        //On change la caméra.
        setSceneRect(_xCamera * Config::Config::TILE_SIZE,_yCamera * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2);
    }

}
