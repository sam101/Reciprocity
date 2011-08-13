#ifndef GUI_ENTITYINFOWIDGET_H
#define GUI_ENTITYINFOWIDGET_H
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <Client/DataHandler.h>
#include <Map/Entity.h>
namespace GUI
{
    /**
      * Affiche les informations sur l'entité actuellement selectionnée
      * @brief Affiche les informations sur l'entité actuellement selectionnée
      * @author Sam101
      */
    class EntityInfoWidget : public QWidget
    {
        Q_OBJECT
        protected:
            /**
              * Entité actuelle
              */
            Map::Entity *_entity;
            /**
              * Label contenant l'image de l'entité
              */
            QLabel *_imageLabel;
            /**
              * Label contenant le texte de l'entité
              */
            QLabel *_infoLabel;
            /**
              * Pointeur vers le DataHandler
              */
            Client::DataHandler *_dataHandler;
       public:
            /**
              * Constructeur
              */
            EntityInfoWidget();
            /**
              * Change le dataHandler actuel
              */
            void setDataHandler(Client::DataHandler *dataHandler);
            /**
              * Affiche une entité
              */
            void displayEntity(Map::Entity *entity);

    };
}
#endif //GUI_ENTITYINFOWIDGET_H
