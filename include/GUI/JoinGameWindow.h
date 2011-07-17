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
        signals:
            /**
              * Emit quand le bouton "Se connecter" est cliqué.
              */
            void wantToConnect(QString address, qint32 port, QString login, QString hash);
        public slots:
            /**
              * Appelé au clic sur "Se connecter"
              */
            void connectButton_clicked();
    };
}
#endif //GUI_JOINGAMEWINDOW_H
