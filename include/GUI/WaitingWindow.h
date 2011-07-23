#ifndef GUI_WAITINGWINDOW_H
#define GUI_WAITINGWINDOW_H
#include <QtGui/QListView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QStringListModel>
#include <QtGui/QWidget>

#include <Client/Client.h>
namespace GUI
{
    /**
      * Fenêtre affichée avant qu'une partie aie commencé.
      * Permet aux joueurs de discuter entre eux.
      * @brief Fenêtre affichée avant qu'une partie aie commencé
      * @author Sam101
      */
    class WaitingWindow : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Liste des messages
              */
            QListWidget *_messages;
            /**
              * Modèle de la liste des joueurs
              */
            QStringListModel *_playerList;
            /**
              * Ligne de texte à envoyer
              */
            QLineEdit *_text;
            /**
              * Vue de la liste des joueurs
              */
            QListView *_playerView;
            /**
              * Pointeur vers l'objet de Client
              */
            Client::Client *_client;
        public:
            /**
              * Constructeur
              */
            WaitingWindow(QWidget *parent = 0);
        public slots:
            /**
              * Change le client actuel
              */
            void setClient(Client::Client *client);
            /**
              * Appelé au clic sur le bouton "quitter"
              */
            void quitHandler();
            /**
              * Indique que le joueur veut lancer la partie
              */
            void launchGameRequested();
        signals:
            /**
              * Indique que le joueur veut se deconnecter
              */
            void logoutRequested();


    };
}
#endif //GUI_WAITINGWINDOW_H
