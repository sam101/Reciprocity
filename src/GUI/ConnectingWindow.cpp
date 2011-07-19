#include <GUI/ConnectingWindow.h>
namespace GUI
{
    /**
      * Constructeur
      */
    ConnectingWindow::ConnectingWindow()
    {
        //On masque la fenêtre.
        hide();
    }
    /**
      * Affiche la fenêtre et lance la connexion
      */
    void ConnectingWindow::start(QString address, qint32 port, QString login, QString hash)
    {
        //On affiche la fenêtre.
        show();
    }
}
