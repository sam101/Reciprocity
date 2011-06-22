#include <Viewer/ViewerView.h>
#include <Config/Config.h>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerView::ViewerView() :
    _scene(NULL),
    _world(NULL)
    {
        //On alloue l'objet de monde
        _world = new World::World;
        //On alloue la scène.
        _scene = new ViewerScene(_world);
        setScene(_scene);
        //On gère la caméra
        _scene->setSceneRect(0,0,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
        //On affiche le premier chunk
        _scene->addChunk(1,1);
    }
    /**
      * Destructeur
      */
    ViewerView::~ViewerView()
    {
        delete _world;
        delete _scene;
    }
}
