#ifndef GUI_TILEINFOWIDGET_H
#define GUI_TILEINFOWIDGET_H
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <Map/Tile.h>
namespace GUI
{
    /**
      * Affiche les informations relatives à une tile
      * @brief Affiche les informations relatives à une tile
      * @author Sam101
      */
    class TileInfoWidget : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Tile actuelle
              */
            Map::Tile *_tile;
            /**
              * Label contenant l'image de la tile
              */
            QLabel *_imageLabel;
            /**
              * Label contenant les informations sur la tile
              */
            QLabel *_infoLabel;
            /**
              * Tableau contenant les pixmap des tiles
              */
            QVector<QPixmap> _tiles;
    public:
            /**
              * Constructeur
              */
            TileInfoWidget();
        public slots:
            /**
              * Affiche les informations sur la tile.
              */
            void displayTile(Map::Tile *tile);
    };
}
#endif //GUI_TILEINFOWIDGET_H

