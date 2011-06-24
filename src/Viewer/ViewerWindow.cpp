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
        //On ajoute le widget de zoom
        _zoom = new ViewerZoomWidget;
        addToolBar(_zoom);
        //On connecte le signal à la view
        connect(_zoom,SIGNAL(zoomChanged(qreal)),_view,SLOT(setZoom(qreal)));
        //On change la taille de la fenêtre.
        resize(_view->scene()->sceneRect().width() + 32,_view->scene()->sceneRect().height() + 32);
    }
}
