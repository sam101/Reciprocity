#include <GUI/EntityInfoWidget.h>
#include <Graphics/Provider.h>
#include <QtGui/QHBoxLayout>
using namespace Graphics;
namespace GUI
{
    /**
      * Constructeur
      */
    EntityInfoWidget::EntityInfoWidget() :
    _entity(NULL)
    {
        //On construit le Layout.
        QHBoxLayout *layout = new QHBoxLayout;
        setLayout(layout);
        //On construit les deux widgets
        _imageLabel = new QLabel;
        layout->addWidget(_imageLabel);
        _infoLabel = new QLabel(tr("Pas de selection"));
        layout->addWidget(_infoLabel);
    }
    /**
      * Affiche une entité
      */
    void EntityInfoWidget::displayEntity(Map::Entity *entity)
    {
        _entity = entity;
        //On vérifie qu'il y'a bien une entité
        if (entity == NULL)
        {
            _infoLabel->setText(tr("Pas de selection"));
        }
        //On change les informations
        _imageLabel->setPixmap(QPixmap::fromImage(Provider::getEntityI("entity")));
        _infoLabel->setText("(" + QString::number(entity->getX()) + "," + QString::number(entity->getY()) + ")");
    }
}
