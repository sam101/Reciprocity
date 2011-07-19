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
      * Indique que le nom d'hote a été trouvé
      */
    void ConnectingWindow::hostFoundMessage()
    {
        _label->setText(tr("Statut: Nom d'hote trouvé, connexion en cours..."));
        _bar->setValue(10);
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
    /**
      * Indique qu'une erreur inconnue s'est produite
      */
    void ConnectingWindow::unknownErrorOccurred()
    {
        _label->setText(tr("Statut: Une erreur inconnue s'est produite"));
    }
    /**
      * Envoyé quand la connexion a été refusée
      */
    void ConnectingWindow::connectionRefusedError()
    {
        _label->setText(tr("Statut: Erreur: La connexion a été refusée."));
    }

    /**
      * Indique que l'hote n'existe pas
      */
    void ConnectingWindow::hostNotFoundError()
    {
        _label->setText(tr("Statut: Erreur: Le nom d'hôte n'existe pas"));
    }
}
