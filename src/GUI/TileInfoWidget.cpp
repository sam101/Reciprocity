#include <GUI/TileInfoWidget.h>
#include <QtGui/QHBoxLayout>
#include <QtCore/QDebug>
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
        _tiles.append(Provider::getTile("oasis"));
        _tiles.append(Provider::getTile("iceberg"));
        _tiles.append(Provider::getTile("volcano"));

    }
    /**
      * Affiche les informations sur la tile.
      */
    void TileInfoWidget::displayTile(Map::Tile *tile)
    {
        //On change l'objet actuel
        _tile = tile;
        if (tile == NULL)
        {
            _imageLabel->setPixmap(_tiles[0]);
            _infoLabel->setText(tr("Hors terrain"));
            return;
        }
        //On affiche l'image.
        _imageLabel->setPixmap(_tiles[tile->getType()]);
        //On affiche le texte
        QString text;
        switch (tile->getType())
        {
            case Map::SEA:
                text = tr("Mer");
            break;
            case Map::LOWLAND:
                text = tr("Plaines");
            break;
            case Map::FOREST:
                text = tr("Foret");
            break;
            case Map::LAKE:
                text = tr("Lac");
            break;
            case Map::RIVER:
                text = tr("Rivière");
            break;
            case Map::MOUNTAIN:
                text = tr("Montagne");
            break;
            case Map::BEACH:
                text = tr("Plage");
            break;
            case Map::SWAMP:
                text = tr("Marais");
            break;
            default:
                text = tr("Inconnu");
        }
        _infoLabel->setText(text + " \n (" + QString::number((tile->getX())) + "," + QString::number(tile->getY()) + ") - " + QString::number(tile->getOutput()) + "%");
    }
}
