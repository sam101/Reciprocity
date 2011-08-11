#include <GUI/JoinGameWindow.h>
#include <Config/Config.h>
#include <QtGui/QFormLayout>
#include <QtGui/QMessageBox>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    JoinGameWindow::JoinGameWindow(QWidget *parent) :
    QWidget(parent)
    {
        setWindowTitle(tr("Reciprocity - Rejoindre une partie"));

        QVBoxLayout *layout = new QVBoxLayout;
        setLayout(layout);
        //On construit la form
        QFormLayout *form = new QFormLayout;
        layout->addLayout(form);
        //On ajoute le pseudo du joueur
        _login = new QLineEdit;
        form->addRow(tr("Pseudo à utiliser:"),_login);
        //On ajoute le hash du joueur
        _hash = new QLineEdit;
        form->addRow(tr("Hash:"),_hash);
            //On ajoute l'addresse du serveur
            _address = new QLineEdit;
            _address->setText("localhost");
        form->addRow(tr("Adresse du serveur:"),_address);
        //On ajoute le port
        _port = new QSpinBox;
        _port->setMinimum(1);
        _port->setMaximum(65535);
        _port->setValue(Config::Config::SERVER_PORT);
        form->addRow(tr("Port:"),_port);
        //On ajoute le bouton
        QPushButton *connectButton = new QPushButton(tr("Se connecter !"));
        layout->addWidget(connectButton);
        connect(connectButton,SIGNAL(clicked()),this,SLOT(connectButton_clicked()));

    }
    /**
      * Appelé au clic sur "Se connecter"
      */
    void JoinGameWindow::connectButton_clicked()
    {
        if (_login->text() == "")
        {
            QMessageBox::critical(this,tr("Le pseudo à utiliser doit être rempli"),tr("Le pseudo à utiliser doit être rempli."));
        }
        else if (_hash->text() == "")
        {
            QMessageBox::critical(this,tr("Le hash à utiliser doit être rempli"),tr("Le pseudo à utiliser doit être rempli."));

        }
        else if (_address->text() == "")
        {
            QMessageBox::critical(this,tr("L'ip du serveur à rejoindre doit être remplie"),tr("L'ip du serveur à rejoindre doit être remplie"));
        }
        else
        {
            hide();
            emit wantToConnect(_address->text(),_port->value(),_login->text(),_hash->text());
        }
    }
}
