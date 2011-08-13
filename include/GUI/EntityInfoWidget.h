#ifndef GUI_ENTITYINFOWIDGET_H
#define GUI_ENTITYINFOWIDGET_H
#include <QtGui/QLabel>
#include <QtGui/QWidget>
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
       public:
            /**
              * Constructeur
              */
            EntityInfoWidget();

    };
}
#endif //GUI_ENTITYINFOWIDGET_H
