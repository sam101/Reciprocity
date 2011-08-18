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
        addWidget(_endTurn);
        addSeparator();
        //On construit le bouton de selection
        _select = new QPushButton(tr("Selectionner"));
        addWidget(_select);
        addSeparator();
        //On construit le bouton de déplacement
        _move = new QPushButton(tr("Déplacement"));
        _move->setEnabled(false);
        addWidget(_move);
        addSeparator();
        //On construit le bouton pour construire
        _build = new QPushButton(tr("Construire"));
        _build->setEnabled(false);
        addWidget(_build);
        addSeparator();
        //On ajoute le TileInfoWidget
        _tileInfo = new TileInfoWidget;
        addWidget(_tileInfo);
        addSeparator();
        //On ajoute le EntityInfoWidget
        _entityInfo = new EntityInfoWidget;
        addWidget(_entityInfo);
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
      * Affiche une entité dans le EntityInfoWidget
      */
    void ActionToolBar::displayEntity(Map::Entity *entity)
    {
        if (entity == NULL)
        {
            _move->setEnabled(false);
            _build->setEnabled(false);
        }
        else
        {
            _move->setEnabled(true);
            _build->setEnabled(true);
        }
        _entityInfo->displayEntity(entity);
    }
}
