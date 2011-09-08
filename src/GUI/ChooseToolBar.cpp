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
        _separator1 = addSeparator();

        //On construit les boutons d'actions
        QPushButton *build = new QPushButton(tr("Construire"));
        _build = addWidget(build);
        _separator2 = addSeparator();
        QPushButton *work = new QPushButton(tr("Travailler"));
        _work = addWidget(work);

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

        _separator2->setVisible(false);
        _separator1->setVisible(false);
    }
    /**
      * Affiche les boutons d'action
      */
    void ChooseToolBar::showActions()
    {
        _back->setVisible(true);
        _build->setVisible(true);
        _work->setVisible(true);

        _separator2->setVisible(true);
        _separator1->setVisible(true);

    }
}
