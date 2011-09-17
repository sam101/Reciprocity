#include <GUI/BuildingInfoWidget.h>
#include <QtGui/QHBoxLayout>
#include <QtCore/QDebug>
#include <Graphics/Provider.h>
namespace GUI
{
    /**
      * Constructeur
      */
    BuildingInfoWidget::BuildingInfoWidget()
    {
        //On construit le Layout
        QHBoxLayout *layout = new QHBoxLayout;
        setLayout(layout);
        //On construit les deux labels
        _imageLabel = new QLabel;
        layout->addWidget(_imageLabel);
        _infoLabel = new QLabel(tr("Pas de selection"));
        layout->addWidget(_infoLabel);
        //On construit le tableau des batiments
        //TODO: Faire un truc mieux.
        _tiles.append(Provider::getBuilding("none").toImage());
        _tiles.append(Provider::getBuilding("house").toImage());
        _tiles.append(Provider::getBuilding("farmland").toImage());
        _tiles.append(Provider::getBuilding("road").toImage());
    }
    /**
      * Affiche les informations sur le batiment
      */

}
