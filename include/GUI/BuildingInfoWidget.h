#ifndef GUI_BUILDINGINFOWIDGET_H
#define GUI_BUILDINGINFOWIDGET_H
#include <Map/Building.h>
#include <Map/Tile.h>
#include <QtGui/QLabel>
#include <QtGui/QPixmap>
#include <QtCore/QVector>
#include <QtGui/QWidget>
namespace GUI
{
    /**
      * Affiche les informations relatives à un batiment selectionné
      * @brief Affiche les informations relatives à un batiment selectionné
      * @author Sam101
      */
    class BuildingInfoWidget : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Batiment actuel
              */
            Map::Building *_building;
            /**
              * Label contenant l'image du batiment
              */
            QLabel *_imageLabel;
            /**
              * Label contenant les infos sur le batiment
              */
            QLabel *_infoLabel;
            /**
              * Tableau contenant les pixmap des batiments
              */
            QVector<QPixmap> _buildings;
        public:
            /**
              * Constructeur
              */
            BuildingInfoWidget();
            /**
              * Affiche les informations sur le batiment et sur la tile sous-jacente
              */
            void displayBuilding(Map::Building *building, Map::Tile *tile);
    };
}
#endif //GUI_BUILDINGINFOWIDGET_H

