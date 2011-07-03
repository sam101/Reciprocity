#include <GUI/StartWindow.h>
#include <QtGui/QVBoxLayout>
#include <Config/Config.h>
#include <QtGui/QLabel>
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
    }
}
