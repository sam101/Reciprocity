#include <GUI/ChooseToolBar.h>
#include <Config/Config.h>
#include <Config/CostsConfig.h>
#include <QtCore/QDebug>
using namespace Config;
namespace GUI
{
    /**
      * Constructeur
      */
    ChooseToolBar::ChooseToolBar()
    {
        //On définit le nom de l'objet
        setObjectName("ChooseToolBar");
        //On construit le bouton de retour
        QPushButton *back = new QPushButton(tr("<-"));
        connect(back,SIGNAL(clicked()),this,SLOT(showNothing()));
        _back = addWidget(back);
        _separators[0] = addSeparator();

        //On construit les boutons
        QPushButton *move = new QPushButton(tr("Déplacement"));
        _move = addWidget(move);

        QPushButton *house = new QPushButton(tr("Maison"));
        house->setToolTip(tr("Maison - ") + QString::number(CostsConfig::COST_HOUSE_WOOD) + tr("Bois") );
        connect(house,SIGNAL(clicked()),this,SLOT(houseClicked()));
        _house = addWidget(house);

        _separators[1] = addSeparator();

        QPushButton *build = new QPushButton(tr("Construire"));
        _build = addWidget(build);
        connect(build,SIGNAL(clicked()),this,SLOT(showBuildings()));

        QPushButton *field = new QPushButton(tr("Champ"));
        connect(field,SIGNAL(clicked()),this,SLOT(fieldClicked()));
        _field = addWidget(field);

        _separators[2] = addSeparator();

        QPushButton *work = new QPushButton(tr("Travailler"));
        connect(work,SIGNAL(clicked()),this,SLOT(workClicked()));
        _work = addWidget(work);

        QPushButton *road = new QPushButton(tr("Route"));
        connect(road,SIGNAL(clicked()),this,SLOT(roadClicked()));
        _road = addWidget(road);

        _separators[3] = addSeparator();

        QPushButton *wall = new QPushButton(tr("Mur"));
        connect(wall,SIGNAL(clicked()),this,SLOT(wallClicked()));
        _wall = addWidget(wall);

        _separators[4] = addSeparator();

        QPushButton *tower = new QPushButton(tr("Tour"));
        connect(tower,SIGNAL(clicked()),this,SLOT(towerClicked()));
        _tower = addWidget(tower);

        _separators[5] = addSeparator();

        showNothing();
    }
    /**
      * Desactive tout affichage
      */
    void ChooseToolBar::showNothing()
    {
        _back->setVisible(false);
        _move->setVisible(false);
        _build->setVisible(false);
        _work->setVisible(false);

        _house->setVisible(false);
        _field->setVisible(false);
        _road->setVisible(false);
        _wall->setVisible(false);
        _tower->setVisible(false);

        for (int i = 0; i < 6; i++)
        {
            _separators[i]->setVisible(false);
        }

    }
    /**
      * Affiche les boutons d'action
      */
    void ChooseToolBar::showActions()
    {
        _back->setVisible(true);
        _move->setVisible(true);
        _build->setVisible(true);
        _work->setVisible(true);

        _house->setVisible(false);
        _field->setVisible(false);
        _road->setVisible(false);
        _wall->setVisible(false);
        _tower->setVisible(false);

        for (int i = 0; i < 6; i++)
        {
            _separators[i]->setVisible(false);
        }
        _separators[0]->setVisible(true);
        _separators[1]->setVisible(true);
        _separators[2]->setVisible(true);

    }
    /**
      * Affiche les boutons de construction
      */
    void ChooseToolBar::showBuildings()
    {
        _back->setVisible(true);
        _build->setVisible(false);
        _move->setVisible(false);
        _work->setVisible(false);

        _house->setVisible(true);
        _field->setVisible(true);
        _road->setVisible(true);
        _wall->setVisible(true);
        _tower->setVisible(true);

        for (int i = 0; i < 5; i++)
        {
            _separators[i]->setVisible(true);
        }
        _separators[5]->setVisible(false);
    }
    /**
      * Appelé au clic sur le bouton "se déplacer"
      */
    void ChooseToolBar::moveClicked()
    {
        emit moveRequested();
    }

    /**
      * Appelé au clic sur le bouton "travailler"
      */
    void ChooseToolBar::workClicked()
    {
        emit workRequested();
    }
    /**
      * Appelé au clic sur le bouton "Maison"
      */
    void ChooseToolBar::houseClicked()
    {
        emit buildRequested(Map::HOUSE);
    }
    /**
      * Appelé au clic sur le bouton "Champ"
      */
    void ChooseToolBar::fieldClicked()
    {
        emit buildRequested(Map::FARMLAND);
    }
    /**
      * Appelé au clic sur le bouton "Route"
      */
    void ChooseToolBar::roadClicked()
    {
        emit buildRequested(Map::ROAD);
    }
    /**
      * Appelé au clic sur le bouton "Mur"
      */
    void ChooseToolBar::wallClicked()
    {
        emit buildRequested(Map::WALL);
    }
    /**
      * Appelé au clic sur le bouton "Tour"
      */
    void ChooseToolBar::towerClicked()
    {
        emit buildRequested(Map::TOWER);
    }
}
