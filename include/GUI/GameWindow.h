#ifndef GUI_GAMEWINDOW_H
#define GUI_GAMEWINDOW_H
#include <QtGui/QMainWindow>
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
        public:
            /**
              * Constructeur
              */
            GameWindow();
        public slots:
            /**
              * Change l'objet client actuel
              * (QObject: hack pour contourner limitation de moc)
              */
            void setClient(QObject *client);
    };
}
#endif //GUI_GAMEWINDOW_H
