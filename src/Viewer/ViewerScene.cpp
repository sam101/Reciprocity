#include <Viewer/ViewerScene.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerScene::ViewerScene(World::World *world) :
    _world(world)
    {
        //On gère la caméra
        setSceneRect(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
    }
    /**
      * Ajoute un chunk à la liste des chunk de la scène
      */
    void ViewerScene::addChunk(qint32 xChunk, qint32 yChunk)
    {
        //On vérifie que le chunk n'existe pas déjà.
        if (_chunks.contains(QPair<qint32,qint32>(xChunk,yChunk)))
        {
            return;
        }
        //On ajoute le chunk à la QMap.
        _chunks[QPair<qint32,qint32>(xChunk,yChunk)] = new Graphics::TileChunkItem(_world->getChunk(xChunk,yChunk));
        //On ajoute le chunk à la scène
        addItem(_chunks[QPair<qint32,qint32>(xChunk,yChunk)]);
    }
}
