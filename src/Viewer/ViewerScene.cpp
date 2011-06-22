#include <Viewer/ViewerScene.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
#include <QtGui/QKeyEvent>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerScene::ViewerScene(World::World *world) :
    _xCamera(0),
    _yCamera(0),
    _world(world)
    {

        //On gère la caméra
        setSceneRect(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2);
    }
    /**
      * Ajoute un chunk à la liste des chunk de la scène
      */
    void ViewerScene::addChunk(qint32 xChunk, qint32 yChunk)
    {
        if (xChunk == 0 || yChunk == 0)
        {
            return;
        }
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
    /**
      * Appelé à l'appui sur une touche.
      * Bouge la caméra.
      */
    void ViewerScene::keyPressEvent(QKeyEvent *event)
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
        //On genère les chunk liés à la caméra.
        //On calcule la position de la caméra par rapport au chunk.
        qint32 xPos = _xCamera / Config::Config::CHUNK_SIZE;
        qint32 yPos = _yCamera / Config::Config::CHUNK_SIZE;
        //On genère les deux chunk les plus loins par rapport à la caméra.
        for (int i = xPos - 2; i <= xPos + 2; i++)
        {
            for (int j = yPos - 2; j <= yPos + 2; j++)
            {
                addChunk(i,j);
            }
        }
    }
}
