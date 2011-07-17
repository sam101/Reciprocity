#ifndef GUI_JOINGAMEWINDOW_H
#define GUI_JOINGAMEWINDOW_H
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
namespace GUI
{
    /**
      * Gère la fenêtre permettant de rejoindre une partie
      * @brief Gère la fenêtre permettant de rejoindre une partie
      * @author Sam101
      */
    class JoinGameWindow : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Login du joueur à utiliser
              */
            QLineEdit *_login;
            /**
              * Hash du joueur
              */
            QLineEdit *_hash;
            /**
              * Adresse du serveur à rejoindre
              */
            QLineEdit *_address;
            /**
              * Port du serveur
              */
            QSpinBox *_port;
        public:
            /**
              * Constructeur
              */
            JoinGameWindow(QWidget *parent = 0);
    };
}
#endif //GUI_JOINGAMEWINDOW_H
