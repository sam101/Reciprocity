#include <Viewer/ViewerZoomWidget.h>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerZoomWidget::ViewerZoomWidget()
    {
        //On construit le slider
        _slider = new QSlider(Qt::Horizontal);
        addWidget(_slider);
    }
}
