#ifndef GUI_CHATDOCKWIDGET_H
#define GUI_CHATDOCKWIDGET_H
#include <Client/Client.h>

#include <QtGui/QDockWidget>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
namespace GUI
{
    /**
      * DockWidget s'occupant de la discussion entre les joueurs
      * @brief DockWidget s'occupant de la discussion entre les joueurs
      * @author Sam101
      */
    class ChatDockWidget : public QDockWidget
    {
        Q_OBJECT
        protected:
            /**
              * Liste des messages
              */
            QListWidget *_messages;
            /**
              * Ligne du texte à envoyer
              */
            QLineEdit *_text;
            /**
              * Pointeur vers l'objet Client
              */
            Client::Client *_client;
       public:
            /**
              * Constructeur
              */
            ChatDockWidget();
            /**
              * Change l'objet client actuel
              */
            void setClient(Client::Client *client);
        public slots:
            /**
              * Appelé à la reception d'un message
              * Ajoute un message
              */
            void messageRecevied(QString sender, QString contents);

    };
}
#endif //GUI_CHATDOCKWIDGET_H
