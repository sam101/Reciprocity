#ifndef GUI_GAMEWINDOW_H
#define GUI_GAMEWINDOW_H
#include <QtGui/QGraphicsView>
#include <QtGui/QMainWindow>

#include <GUI/ActionToolBar.h>
#include <GUI/ChatDockWidget.h>
#include <GUI/ChooseToolBar.h>
#include <GUI/GameScene.h>
#include <GUI/SummaryWidget.h>

#include <Client/Client.h>
#include <Client/DataHandler.h>
namespace GUI
{
    /**
      * Fenêtre principale en jeu
      * @brief Fenêtre principale en jeu
      * @author Sam101
      */
    class GameWindow : public QMainWindow
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers l'objet Client
              */
            Client::Client *_client;
            /**
              * Pointeur vers le DataHandler
              */
            Client::DataHandler *_dataHandler;
            /**
              * Pointeur vers la GraphicsView de la Window
              */
            QGraphicsView *_view;
            /**
              * Pointeur vers la GraphicsScene
              */
            GameScene *_scene;
            /**
              * Pointeur vers le ChatDock
              */
            ChatDockWidget *_chatDock;
            /**
              * Pointeur vers la ActionToolBar
              */
            ActionToolBar *_actionToolBar;
            /**
              * Pointeur vers la ChooseToolBar
              */
            ChooseToolBar *_chooseToolBar;
            /**
              * Pointeur vers le SummaryWidget
              */
            SummaryWidget *_summaryWidget;
            /**
              * Id de l'entité actuellement sélectionnée
              */
            qint32 _currentEntity;

            /**
              * Type de widget pouvant être affiché
              */
            enum WidgetType
            {
                MAP = 0,
                SUMMARY = 1
            };
            /**
              * Indique le widget actuellement affiché
              */
            WidgetType _widgetShow;
        public:
            /**
              * Constructeur
              */
            GameWindow();
            /**
              * Destructeur
              */
            virtual ~GameWindow();
        public slots:
            /**
              * Change l'objet client actuel
              * (QObject: hack pour contourner limitation de moc)
              */
            void setClient(QObject *client);
            /**
              * Change le numéro de tour actuel
              */
            void setTurn(qint32 turn);
            /**
              * Sauvegarde l'état de la fenêtre
              */
            void saveWindowState();
            /**
              * Commence la partie
              */
            void beginGame();
            /**
              * Ajoute un chunk
              */
            void addChunk(Chunk::Chunk *chunk);
            /**
              * Met à jour un chunk
              */
            void updateChunk(Chunk::Chunk *chunk);
            /**
              * Ajoute une entité
              */
            void addEntity(Map::Entity *entity);
            /**
              * Met à jour une entité
              */
            void updateEntity(Map::Entity *entity);
            /**
              * Appelé quand une tile a été selectionnée.
              * Transmet l'information à ActionBar pour
              * changer l'indic.
              */
            void tileSelected(qint32 x, qint32 y);
            /**
              * Appelé quand une demande de mouvement d'unité a été envoyée
              */
            void moveSelected(qint32 x, qint32 y);
            /**
              * Appelé quand une demande de construction a été faite
              */
            void buildRequested(Map::BuildingType type);
            /**
              * Appelé quand l'utilisateur souhaite voir le récapitulatif
              */
            void summaryRequested();
            /**
              * Appelé quand une demande de travail est faite
              */
            void workRequested();
            /**
              * Appelé quand le joueur veut finir son tour
              */
            void endTurn();
            /**
              * Change le type actuel de selection pour "Selectionner"
              */
            void setSelect();
            /**
              * Change le type actuel de selection pour "Se déplacer"
              */
            void setMove();
    };
}
#endif //GUI_GAMEWINDOW_H
