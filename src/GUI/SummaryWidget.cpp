#include <GUI/SummaryWidget.h>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    SummaryWidget::SummaryWidget() :
    _dataHandler(NULL)
    {
        //On construit le layout principal.
        QVBoxLayout *layout = new QVBoxLayout;
        setLayout(layout);
        //On construit le titre.
        _title = new QLabel("<h1>" + tr("Récapitulatif: ") + _login + "</h1>");
        layout->addWidget(_title);
        //On construit la tableView.
        _tableView = new QTableView;
        //On construit le modèle
        _model = new QStandardItemModel;
        _tableView->setModel(_model);
    }
    /**
      * Change le client et le dataHandler actuel
      */
    void SummaryWidget::setClient(Client::Client *client)
    {
        //On met à jour les données
        _client = client;
        _dataHandler = client->getDataHandler();
        //On reconstruit le modèle
        updateEntityList();
    }
    /**
      * Met à jour la liste des entités
      */
    void SummaryWidget::updateEntityList()
    {
        //On vide le modèle
        _model->clear();
        //On itère sur la liste des entités
        QMapIterator<qint32, Map::Entity*> it(_dataHandler->getEntities());
        while (it.hasNext())
        {
            //On recupère l'entité
            Map::Entity *entity = it.next().value();
            //On ajoute l'entité que si elle nous appartient
            if (entity->getOwner() == _client->getId())
            {

            }
        }
    }
}
