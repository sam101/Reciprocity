#ifndef VIEWER_VIEWERZOOMWIDGET_H
#define VIEWER_VIEWERZOOMWIDGET_H
#include <QtGui/QSlider>
#include <QtGui/QToolBar>
namespace Viewer
{
    /**
      * Gère l'indicateur de zoom de la fenêtre.
      */
    class ViewerZoomWidget : public QToolBar
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers le slider
              */
            QSlider *_slider;
        public:
            /**
              * Constructeur
              */
            ViewerZoomWidget();
    };
}
#endif //VIEWER_VIEWERZOOMWIDGET_H
