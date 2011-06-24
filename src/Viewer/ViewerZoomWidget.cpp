#include <Viewer/ViewerZoomWidget.h>
#include <QDebug>
namespace Viewer
{
    /**
      * Constructeur
      */
    ViewerZoomWidget::ViewerZoomWidget()
    {
        //On construit le slider
        _slider = new QSlider(Qt::Horizontal);
        _slider->setMinimum(1);
        _slider->setMaximum(20);
        addWidget(_slider);
        //On connecte le signal du slider au slot de la toolbar
        connect(_slider,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
    }
    /**
      * Appelé quand le slider à bougé
      */
    void ViewerZoomWidget::sliderChanged(int value)
    {
        qDebug() << "Value:" << value / 10.0;
        emit zoomChanged((value) / 10.0);
    }
}
