#ifndef GUI_ACTIONTOOLBAR_H
#define GUI_ACTIONTOOLBAR_H
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <Client/DataHandler.h>
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
              * Bouton pour la fin du tour
              */
            QPushButton *_endTurn;
            /**
              * Bouton de selection
              */
            QPushButton *_select;
            /**
              * Bouton utilisé pour déplacer une entité
              */
            QPushButton *_move;
            /**
              * Bouton utilisé pour construire
              */
            QPushButton *_build;

            /**
              * Pointeur vers le TileInfoWidget
              */
            TileInfoWidget *_tileInfo;
            /**
              * Poniteur vers le TileInfoWidget
              */
            EntityInfoWidget *_entityInfo;
            /**
              * Pointeur vers le DataHandler
              */
            Client::DataHandler *_dataHandler;
    public:
            /**
              * Constructeur
              */
            ActionToolBar();
        public slots:
            /**
              * Change le DataHandler actuel
              */
            void setDataHandler(Client::DataHandler *dataHandler);
            /**
              * Affiche une tile dans le TileInfo
              */
            void displayTile(Map::Tile *tile);
            /**
              * Affiche une entité dans le EntityInfoWidget
              */
            void displayEntity(Map::Entity *entity);
    };
}
#endif //GUI_ACTIONTOOLBAR_H
