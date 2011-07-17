#include <GUI/JoinGameWindow.h>
#include <Config/Config.h>
#include <QtGui/QFormLayout>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    JoinGameWindow::JoinGameWindow(QWidget *parent) :
    QWidget(parent)
    {
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
        form->addRow(tr("Adresse du serveur:"),_address);
        //On ajoute le port
        _port = new QSpinBox;
        _port->setMinimum(1);
        _port->setMaximum(65535);
        _port->setValue(Config::Config::SERVER_PORT);
        form->addRow(tr("Port:"),_port);

    }
}
