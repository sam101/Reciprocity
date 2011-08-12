#include <GUI/TileInfoWidget.h>
#include <QtGui/QHBoxLayout>
#include <Graphics/Provider.h>
using namespace Graphics;
namespace GUI
{
    /**
      * Constructeur
      */
    TileInfoWidget::TileInfoWidget() :
    _tile(NULL)
    {
        //On construit le Layout
        QHBoxLayout *layout = new QHBoxLayout;
        setLayout(layout);
        //On construit les deux labels
        _imageLabel = new QLabel;
        layout->addWidget(_imageLabel);
        _infoLabel = new QLabel(tr("Pas de selection"));
        layout->addWidget(_infoLabel);
        //On construit le tableau des tiles
        //TODO: Faire un truc mieux
        _tiles.append(Provider::getTile("nothing"));
        _tiles.append(Provider::getTile("sea"));
        _tiles.append(Provider::getTile("lowland"));
        _tiles.append(Provider::getTile("forest"));
        _tiles.append(Provider::getTile("lake"));
        _tiles.append(Provider::getTile("river"));
        _tiles.append(Provider::getTile("mountain"));
        _tiles.append(Provider::getTile("beach"));
        _tiles.append(Provider::getTile("swamp"));

    }
    /**
      * Affiche les informations sur la tile.
      */
    void TileInfoWidget::displayTile(Map::Tile *tile)
    {
        //On change l'objet actuel
        _tile = tile;
        //On affiche l'image.
        _imageLabel->setPixmap(_tiles[tile->getType()]);

    }
}
