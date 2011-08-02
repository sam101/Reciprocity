#ifndef GUI_GAMEWINDOW_H
#define GUI_GAMEWINDOW_H
#include <QtGui/QMainWindow>
#include <Client/Client.h>
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
    };
}
#endif //GUI_GAMEWINDOW_H
