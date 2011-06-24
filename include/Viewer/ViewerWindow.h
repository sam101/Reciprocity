#ifndef VIEWER_VIEWERWINDOW_H
#define VIEWER_VIEWERWINDOW_H
#include <QtGui/QMainWindow>
#include <Viewer/ViewerView.h>
#include <Viewer/ViewerZoomWidget.h>
namespace Viewer
{
    /**
      * Fenêtre principale du viewer
      * @brief Fenêtre principal du viewer
      * @author Sam101
      */
    class ViewerWindow : public QMainWindow
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers la vue actuelle
              */
            ViewerView *_view;
            /**
              * Pointeur vers le ZoomWidget
              */
            ViewerZoomWidget *_zoom;
       public:
            /**
              * Constructeur
              */
            ViewerWindow();
    };
}
#endif //VIEWER_VIEWERWINDOW_H
