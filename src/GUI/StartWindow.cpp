#include <GUI/StartWindow.h>
#include <QtGui/QVBoxLayout>
#include <Config/Config.h>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
namespace GUI
{
    /**
      * Constructeur
      */
    StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent)
    {
        setWindowTitle(tr("Reciprocity"));
        //On construit la fenêtre
        build();
    }
    /**
      * Construit la fenêtre
      */
    void StartWindow::build()
    {
        //On construit le layout.
        QWidget *widget = new QWidget;
        QVBoxLayout *layout = new QVBoxLayout;
        widget->setLayout(layout);
        setCentralWidget(widget);
        //On construit le titre/logo
        QLabel *label = new QLabel(tr("<h1 align=\"center\">Reciprocity</h1>"));
        layout->addWidget(label);
        //On construit le "nouvelle partie"
        layout->addSpacing(42);
        QPushButton *newGame = new QPushButton(tr("Nouvelle partie en local"));
        layout->addWidget(newGame);
        //On construit le "rejoindre partie"
        QPushButton *joinGame = new QPushButton(tr("Rejoindre une partie"));
        layout->addWidget(joinGame);
        //On construit le "jeu sur internet"
        QPushButton *internetPlay = new QPushButton(tr("Jeu sur internet"));
        layout->addWidget(internetPlay);
        //On construit le bouton "quitter le jeu"
        QPushButton *quitGame = new QPushButton(tr("Quitter le jeu"));
        layout->addWidget(quitGame);
    }
}
