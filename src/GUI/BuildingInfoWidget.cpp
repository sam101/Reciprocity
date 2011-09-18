#include <GUI/BuildingInfoWidget.h>
#include <QtGui/QHBoxLayout>
#include <QtCore/QDebug>
#include <Graphics/Provider.h>
using namespace Graphics;
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
        _buildings.append(Provider::getBuilding("none"));
        _buildings.append(Provider::getBuilding("house"));
        _buildings.append(Provider::getBuilding("farmland"));
        _buildings.append(Provider::getBuilding("road"));
    }
    /**
      * Affiche les informations sur le batiment
      */

}
