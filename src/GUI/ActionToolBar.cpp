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
        //On construit le widget
        QWidget *widget = new QWidget;
        //On construit le layout
        QVBoxLayout *layout = new QVBoxLayout;
        widget->setLayout(layout);
        //On construit le bouton de fin de tour
        QPushButton *endTurn = new QPushButton(tr("Fin du tour"));
        layout->addWidget(endTurn);
        //Hack de positionement
        QHBoxLayout *h = new QHBoxLayout;
        layout->addLayout(h);

        addWidget(widget);
    }
}
