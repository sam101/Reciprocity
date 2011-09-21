#ifndef GUI_SUMMARYWIDGET_H
#define GUI_SUMMARYWIDGET_H
#include <Client/Client.h>
#include <Client/DataHandler.h>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QStandardItemModel>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
namespace GUI
{
    /**
      * Contient le récapitulatif des informations du joueur
      * @brief Contient le récapitulatif des informations du joueur
      * @author Sam101
      */
    class SummaryWidget : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers le dataHandler
              */
            Client::DataHandler *_dataHandler;
            /**
              * Pointeur vers l'objet client
              */
            Client::Client *_client;
            /**
              * Login du joueur
              */
            QString _login;
            /**
              * Label contenant le titre
              */
            QLabel *_title;
            /**
              * Pointeur vers la TableView contenant les informations sur les entités
              */
            QTableView *_tableView;
            /**
              * Pointeur vers le modèle
              */
            QStandardItemModel *_model;
        public:
            /**
              * Constructeur
              */
            SummaryWidget();
            /**
              * Change le client et le dataHandler actuel
              */
            void setClient(Client::Client *client);
            /**
              * Met à jour la liste des entités
              */
            void updateEntityList();

    };
}
#endif //GUI_SUMMARYWIDGET_H
