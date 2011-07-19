#ifndef GUI_CONNECTINGWINDOW_H
#define GUI_CONNECTINGWINDOW_H
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>
namespace GUI
{
    /**
      * Fenêtre affichée lors de la connexion au serveur.
      * Informe l'utilisateur de l'avancement de la connexion au serveur.
      * @brief Fenêtre affichée lors de la conenxion au serveur
      * @author Sam101
      */
    class ConnectingWindow : public QWidget
    {
        Q_OBJECT
        public:
            /**
              * Constructeur
              */
            ConnectingWindow();
        public slots:
            /**
              * Affiche la fenêtre et lance la connexion
              */
            void start(QString address, qint32 port, QString login, QString hash);
    };
}
#endif //GUI_CONNECTINGWINDOW_H
