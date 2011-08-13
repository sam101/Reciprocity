#ifndef GUI_ACTIONTOOLBAR_H
#define GUI_ACTIONTOOLBAR_H
#include <QtGui/QToolBar>
#include <GUI/EntityInfoWidget.h>
#include <GUI/TileInfoWidget.h>
namespace GUI
{
    /**
      * DockWidget contenant les actions les plus courantes actuellement réalisables
      * @brief Contient les actions les plus courantes
      * @author Sam101
      */
    class ActionToolBar : public QToolBar
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers le TileInfoWidget
              */
            TileInfoWidget *_tileInfo;
            /**
              * Poniteur vers le EntityInfoWidget
              */
            EntityInfoWidget *_entityInfo;
        public:
            /**
              * Constructeur
              */
            ActionToolBar();
        public slots:
            /**
              * Affiche une tile dans le TileInfo
              */
            void displayTile(Map::Tile *tile);
    };
}
#endif //GUI_ACTIONTOOLBAR_H
