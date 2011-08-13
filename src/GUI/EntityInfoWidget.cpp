#include <GUI/EntityInfoWidget.h>
#include <QtGui/QHBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    EntityInfoWidget::EntityInfoWidget() :
    _entity(NULL)
    {
        //On construit le Layout.
        QHBoxLayout *layout = new QHBoxLayout;
        setLayout(layout);
        //On construit les deux widgets
        _imageLabel = new QLabel;
        layout->addWidget(_imageLabel);
        _infoLabel = new QLabel(tr("Pas de selection"));
        layout->addWidget(_infoLabel);
    }
}
