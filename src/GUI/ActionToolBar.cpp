#include <GUI/ActionToolBar.h>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    ActionToolBar::ActionToolBar()
    {
        setObjectName("ActionToolBar");
        setWindowTitle(tr("Barre d'actions"));
        setFloatable(false);
        //On construit le bouton de fin de tour
        _endTurn = new QPushButton(tr("Fin du tour"));
        connect(_endTurn,SIGNAL(clicked()),this,SLOT(endTurnButtonSelected()));
        addWidget(_endTurn);
        addSeparator();
        //On construit le bouton de selection
        _select = new QPushButton(tr("Selectionner"));
        connect(_select,SIGNAL(clicked()),this,SLOT(selectButtonSelected()));
        addWidget(_select);
        addSeparator();
        //On construit le bouton de déplacement
        _move = new QPushButton(tr("Déplacement"));
        connect(_move,SIGNAL(clicked()),this,SLOT(moveButtonSelected()));
        _move->setEnabled(false);
        addWidget(_move);
        addSeparator();
        //On construit le bouton pour réaliser une action
        _action = new QPushButton(tr("Action"));
        _action->setEnabled(false);
        connect(_action,SIGNAL(clicked()),this,SLOT(actionButtonSelected()));
        addWidget(_action);
        addSeparator();
        //On ajoute le TileInfoWidget
        _tileInfo = new TileInfoWidget;
        _tileInfoAction = addWidget(_tileInfo);
        //On ajotue le BuildingInfoWidget
        _buildingInfo = new BuildingInfoWidget;
        _buildingInfoAction = addWidget(_buildingInfo);
        _buildingInfoAction->setVisible(false);
        addSeparator();
        //On ajoute le EntityInfoWidget
        _entityInfo = new EntityInfoWidget;
        addWidget(_entityInfo);
    }
    /**
      * Ré-active le bouton de fin du tour
      */
    void ActionToolBar::enableEndTurn()
    {
        _endTurn->setEnabled(true);
    }

    /**
      * Appelé à l'appui sur "Fin du tour"
      * Emet le signal indiquant qu'on veut une fin
      * du tour
      */
    void ActionToolBar::endTurnButtonSelected()
    {
        _endTurn->setEnabled(false);
        emit endTurnSelected();
    }

    /**
      * Appelé à l'appui sur Selectionner. Gère
      * l'envoi des signaux correspondant
      */
    void ActionToolBar::selectButtonSelected()
    {
        emit selectSelected();
    }
    /**
      * Appelé à l'appui sur le bouton déplacement,
      * gère l'envoi des signaux correspondant
      */
    void ActionToolBar::moveButtonSelected()
    {
        emit moveSelected();
    }
    /**
      * Appelé à l'appui sur le bouton d'action
      */
    void ActionToolBar::actionButtonSelected()
    {
        emit actionSelected();
    }

    /**
      * Change le DataHandler actuel
      */
    void ActionToolBar::setDataHandler(Client::DataHandler *dataHandler)
    {
        _dataHandler = dataHandler;
        _entityInfo->setDataHandler(dataHandler);
    }
    /**
      * Affiche une tile dans le TileInfo
      */
    void ActionToolBar::displayTile(Map::Tile *tile)
    {
        _tileInfo->displayTile(tile);
    }
    /**
      * Affiche un batiment dans le BuildingInfo
      */
    void ActionToolBar::displayBuilding(Map::Building *building)
    {
        //Si le batiment n'existe pas, on n'affiche pas le BuildingInfoWidget
        if (building->getType() == Map::NONE)
        {
            _tileInfoAction->setVisible(true);
            _buildingInfoAction->setVisible(false);
        }
        //Sinon,on affiche le batiment
        else
        {
            _tileInfoAction->setVisible(false);
            _buildingInfoAction->setVisible(true);
            _buildingInfo->displayBuilding(building);
        }
    }

    /**
      * Affiche une entité dans le EntityInfoWidget
      */
    void ActionToolBar::displayEntity(Map::Entity *entity)
    {
        if (entity == NULL)
        {
            _move->setEnabled(false);
            _action->setEnabled(false);
        }
        else
        {
            _move->setEnabled(true);
            _action->setEnabled(true);
        }
        _entityInfo->displayEntity(entity);
    }
    /**
      * Efface la selection actuelle
      */
    void ActionToolBar::resetSelection()
    {
        _entityInfo->displayEntity(NULL);
        _tileInfo->displayTile(NULL);
    }
}
