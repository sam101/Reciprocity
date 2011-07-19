#include <GUI/StartWindow.h>
#include <Config/Config.h>
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
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
        connect(newGame,SIGNAL(clicked()),this,SLOT(newGame_clicked()));
        //On construit le "rejoindre partie"
        QPushButton *joinGame = new QPushButton(tr("Rejoindre une partie"));
        layout->addWidget(joinGame);
        connect(joinGame,SIGNAL(clicked()),this,SLOT(joinGame_clicked()));
        //On construit le "jeu sur internet"
        QPushButton *internetPlay = new QPushButton(tr("Jeu sur internet"));
        layout->addWidget(internetPlay);
        connect(internetPlay,SIGNAL(clicked()),this,SLOT(internetPlay_clicked()));
        //On construit le bouton "quitter le jeu"
        QPushButton *quitGame = new QPushButton(tr("Quitter le jeu"));
        layout->addWidget(quitGame);
        connect(quitGame,SIGNAL(clicked()),qApp,SLOT(quit()));
    }
    /**
      * Slot appelé lors du clic sur "nouvelle partie"
      */
    void StartWindow::newGame_clicked()
    {
        emit newGameRequested();
    }
    /**
      * Slot appelé lors du clic sur "rejoindre partie"
      */
    void StartWindow::joinGame_clicked()
    {
        hide();
        emit joinGameRequested();
    }
    /**
      * Slot appelé lors du clic sur "jeu sur internet"
      */
    void StartWindow::internetPlay_clicked()
    {
        emit internetPlayRequested();
    }
}
