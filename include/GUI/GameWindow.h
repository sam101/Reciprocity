#ifndef GUI_GAMEWINDOW_H
#define GUI_GAMEWINDOW_H
#include <QtGui/QGraphicsView>
#include <QtGui/QMainWindow>

#include <GUI/ActionToolBar.h>
#include <GUI/ChatDockWidget.h>
#include <GUI/GameScene.h>

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
              * Pointeur vers le ActionsDock
              */
            ActionToolBar *_actionsDock;
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
    };
}
#endif //GUI_GAMEWINDOW_H
