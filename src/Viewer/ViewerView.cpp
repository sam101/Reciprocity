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
        //On change la taille de la fenêtre
        this->resize(_scene->sceneRect().width() + 32,_scene->sceneRect().height() + 32);
        //On affiche les premiers chunk
        _scene->addChunk(1,1);
        _scene->addChunk(-1,1);
        _scene->addChunk(1,-1);
        _scene->addChunk(-1,-1);

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
