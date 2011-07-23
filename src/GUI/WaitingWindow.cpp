#include <GUI/WaitingWindow.h>
#include <QtCore/QDebug>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    WaitingWindow::WaitingWindow(QWidget *parent) :
    QWidget(parent),
    _client(NULL)
    {
        setWindowTitle(tr("Reciprocity - En attente du commencement de la partie..."));
        //On construit le Layout vertical principal
        QVBoxLayout *layout = new QVBoxLayout;
        setLayout(layout);
        //On construit le layout horizontal pour la liste des messages/joueurs
        QHBoxLayout *h = new QHBoxLayout;
        layout->addLayout(h);
        //On construit le widget pour les messages
        _messages = new QListWidget;
        h->addWidget(_messages,5);
        //On construit la vue des joueurs
        _playerList = new QStringListModel;
        _playerView = new QListView;
        _playerView->setModel(_playerList);
        h->addWidget(_playerView,2);
        //On construit le layout pour envoyer un message.
        QHBoxLayout *h2 = new QHBoxLayout;
        layout->addLayout(h2);
        //On construit la zone de texte
        _text = new QLineEdit;
        h2->addWidget(_text,8);
        //On construit le bouton envoyer
        QPushButton *send = new QPushButton(tr("Envoyer !"));
        connect(send,SIGNAL(clicked()),this,SLOT(sendMessageRequested()));
        h2->addWidget(send,2);
        //On construit les boutons d'actions
        QHBoxLayout *h3 = new QHBoxLayout;
        //Bouton pour quitter la partie
        QPushButton *quit = new QPushButton(tr("Quitter"));
        h3->addWidget(quit);
        connect(quit,SIGNAL(clicked()),this,SLOT(quitHandler()));
        //Bouton pour lancer la partie
        //TODO: Ajouter le fait qu'il doit être admin pour lancer la partie
        _launch = new QPushButton(tr("Lancer la partie"));
        _launch->setEnabled(false);
        connect(_launch,SIGNAL(clicked()),this,SLOT(launchGameRequested()));
        h3->addWidget(_launch);
        //Bouton pour kicker un joueur
        _kick = new QPushButton(tr("Kicker"));
        _kick->setEnabled(false);
        h3->addWidget(_kick);
        //On rajoute le Layout
        layout->addLayout(h3);
    }
    /**
      * Change le client actuel
      */
    void WaitingWindow::setClient(QObject *client)
    {
        //Hack du à un bug de la gestion des namespace dans Qt.
        _client = qobject_cast<Client::Client*>(client);
        //On désactive les boutons en fonction de leur utilité.
        _launch->setEnabled(_client->isAdmin());
        _kick->setEnabled(_client->isAdmin());
    }
    /**
      * Appelé au clic sur le bouton "quitter"
      */
    void WaitingWindow::quitHandler()
    {
        emit logoutRequested();
    }
    /**
      * Indique que le joueur veut lancer la partie
      */
    void WaitingWindow::launchGameRequested()
    {
        if (_client == NULL)
        {
            return;
        }
        _client->sendBeginGame();
    }
    /**
      * Indique que le joueur veut envoyer un message
      */
    void WaitingWindow::sendMessageRequested()
    {
        if (_client == NULL)
        {
            return;
        }
        _client->sendChatMessage(_text->text());
        _text->setText("");
    }
    /**
      * Affichage de la fenêtre
      */
    void WaitingWindow::show()
    {
        //On désactive les boutons en fonction de leur utilité.
        _launch->setEnabled(_client->isAdmin());
        _kick->setEnabled(_client->isAdmin());
        //on affiche la fenêtre.
        QWidget::show();
    }
}
