#ifndef GUI_STARTWINDOW_H
#define GUI_STARTWINDOW_H
#include <QtGui/QMainWindow>
namespace GUI
{
    /**
      * Gère la fenêtre de départ du jeu
      * @brief Gère la fenêtre de départ du jeu
      * @author Sam101
      */
    class StartWindow : public QMainWindow
    {
        Q_OBJECT
        protected:
            /**
              * Construit la fenêtre
              */
            void build();
        public:
            /**
              * Constructeur
              */
            StartWindow(QWidget *parent = 0);
        public slots:
    };
}
#endif //GUI_STARTWINDOW_H