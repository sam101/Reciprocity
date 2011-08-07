#ifndef GUI_GAMEWINDOW_H
#define GUI_GAMEWINDOW_H
#include <QtGui/QGraphicsView>
#include <QtGui/QMainWindow>

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
              * Commence la partie
              */
            void beginGame();
    };
}
#endif //GUI_GAMEWINDOW_H
