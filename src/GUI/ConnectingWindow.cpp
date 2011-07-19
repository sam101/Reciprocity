#include <GUI/ConnectingWindow.h>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    ConnectingWindow::ConnectingWindow()
    {
        setWindowTitle(tr("Reciprocity - Connexion en cours..."));
        //On construit le layout
        QVBoxLayout *layout = new QVBoxLayout;
        setLayout(layout);
        //On construit le premier label.
        QLabel *labelTitle = new QLabel(tr("<h1>Connexion en cours...</h1>"));
        layout->addWidget(labelTitle);
        //On construit le label d'informations
        _label = new QLabel(tr("Statut: Connexion non initiée"));
        layout->addWidget(_label);
        //On construit la barre de progression
        _bar = new QProgressBar;
        _bar->setMinimum(0);
        _bar->setMaximum(100);
        layout->addWidget(_bar);
        //On masque la fenêtre.
        hide();
    }
    /**
      * Affiche la fenêtre et lance la connexion
      */
    void ConnectingWindow::start(QString address, qint32 port, QString login, QString hash)
    {
        _label->setText(tr("Statut: Résolution de l'addresse du serveur en cours..."));
        //On affiche la fenêtre.
        show();
    }
}
