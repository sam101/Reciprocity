#ifndef GUI_CONNECTINGWINDOW_H
#define GUI_CONNECTINGWINDOW_H
#include <QtGui/QLabel>
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
        protected:
            /**
              * Label d'informations
              */
            QLabel *_label;
            /**
              * Barre de progression
              */
            QProgressBar *_bar;
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
            /**
              * Indique que le nom d'hote a été trouvé
              */
            void hostFoundMessage();
            /**
              * Indique que la connexion au serveur a été réussie
              */
            void connectedMessage();


            /**
              * Indique qu'une erreur inconnue s'est produite
              */
            void unknownErrorOccurred();
            /**
              * Envoyé quand la connexion a été refusée
              */
            void connectionRefusedError();
            /**
              * Indique que l'hote n'existe pas
              */
            void hostNotFoundError();
    };
}
#endif //GUI_CONNECTINGWINDOW_H
