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
            QPushButton *_action;

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
            /**
              * Ré-active le bouton de fin du tour
              */
            void enableEndTurn();
        public slots:
            /**
              * Appelé à l'appui sur "Fin du tour"
              * Emet le signal indiquant qu'on veut une fin
              * du tour
              */
            void endTurnButtonSelected();
            /**
              * Appelé à l'appui sur Selectionner. Gère
              * l'envoi des signaux correspondant
              */
            void selectButtonSelected();
            /**
              * Appelé à l'appui sur le bouton déplacement,
              * gère l'envoi des signaux correspondant
              */
            void moveButtonSelected();
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
            /**
              * Efface la selection actuelle
              */
            void resetSelection();
       signals:
            /**
              * Emit à l'apui sur "Fin du tour"
              */
            void endTurnSelected();
            /**
              * Emit à l'appui sur "Selectionner"
              */
            void selectSelected();
            /**
              * Emit à l'appui sur "Se déplacer"
              */
            void moveSelected();

    };
}
#endif //GUI_ACTIONTOOLBAR_H
