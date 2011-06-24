#include <Viewer/ViewerView.h>
#include <Config/Config.h>
#include <QtGui/QWheelEvent>
#include <QtOpenGL/QGLWidget>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerView::ViewerView() :
    _scene(NULL),
    _world(NULL),
    _zoom(1)
    {
        //On alloue l'objet de monde
        _world = new World::World;
        //On alloue la scène.
        _scene = new ViewerScene(_world);
        setScene(_scene);
        //On change la taille de la fenêtre
        this->resize(1 * (_scene->sceneRect().width() + 32),1 * (_scene->sceneRect().height() + 32));
        //On affiche les premiers chunk
        _scene->addChunk(1,1);
        _scene->addChunk(-1,1);
        _scene->addChunk(1,-1);
        _scene->addChunk(-1,-1);
        //On active openGL
        setupViewport(new QGLWidget);
        //On scale la view
        this->scale(0.1,0.1);
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
