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
        setWindowTitle(tr("Barre d'actions"));
        setFloatable(false);
        //On construit le bouton de fin de tour
        QPushButton *endTurn = new QPushButton(tr("Fin du tour"));
        addWidget(endTurn);
        addSeparator();
        //On construit le bouton de déplacement
        QPushButton *move = new QPushButton(tr("Déplacement"));
        addWidget(move);
        addSeparator();
        //On construit le bouton pour construire
        QPushButton *build = new QPushButton(tr("Construire"));
        addWidget(build);
        addSeparator();

    }
}