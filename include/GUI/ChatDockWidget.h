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
        public slots:

    };
}
#endif //GUI_CHATDOCKWIDGET_H
