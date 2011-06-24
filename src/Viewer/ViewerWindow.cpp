#include <Viewer/ViewerWindow.h>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerWindow::ViewerWindow()
    {
        //On crée la vue et on la positionne comme widget principal
        _view = new ViewerView;
        setCentralWidget(_view);
        //On change la taille de la fenêtre.
        resize(_view->width(),_view->height());
    }
}
