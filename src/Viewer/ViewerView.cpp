#include <Viewer/ViewerView.h>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerView::ViewerView()
    {
        _world = new World::World;
        _scene = new ViewerScene(_world);
    }
}
