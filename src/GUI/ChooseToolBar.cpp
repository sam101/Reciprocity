#include <GUI/ChooseToolBar.h>
#include <QtCore/QDebug>
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
        QPushButton *build = new QPushButton(tr("Construire"));
        _build = addWidget(build);
        connect(build,SIGNAL(clicked()),this,SLOT(showBuildings()));
        QPushButton *house = new QPushButton(tr("Maison"));
        _house = addWidget(house);
        _separators[1] = addSeparator();
        QPushButton *work = new QPushButton(tr("Travailler"));
        _work = addWidget(work);
        QPushButton *field = new QPushButton(tr("Champ"));
        _field = addWidget(field);
        _separators[2] = addSeparator();
        QPushButton *road = new QPushButton(tr("Route"));
        _road = addWidget(road);
        _separators[3] = addSeparator();
        QPushButton *wall = new QPushButton(tr("Mur"));
        _wall = addWidget(wall);
        _separators[4] = addSeparator();
        QPushButton *tower = new QPushButton(tr("Tour"));
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

    }
    /**
      * Affiche les boutons de construction
      */
    void ChooseToolBar::showBuildings()
    {
        _back->setVisible(true);
        _build->setVisible(false);
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
}
