#include <GUI/ActionToolBar.h>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    ActionToolBar::ActionToolBar()
    {
        //On construit le bouton de fin de tour
        QPushButton *endTurn = new QPushButton(tr("Fin du tour"));
        addWidget(endTurn);
        //On construit le bouton de déplacement
        QPushButton *move = new QPushButton(tr("Déplacement"));
        addWidget(move);
        //On construit le bouton pour construire
        QPushButton *build = new QPushButton(tr("Construire"));
        addWidget(build);


    }
}
