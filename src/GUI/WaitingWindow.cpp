#include <GUI/WaitingWindow.h>
#include <QtCore/QDebug>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
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
        qApp->exit();
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
        //On vérifie que le texte n'est pas nul.
        if (_text->text() != "")
        {
            _client->sendChatMessage(_text->text());
        }
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
        //On connecte le signal de Client avec addMessage
        connect(_client,SIGNAL(messageRecevied(QString,QString)),this,SLOT(addMessage(QString,QString)));
        //On connecte le signal de deconnexion du serveur
        connect(_client,SIGNAL(serverHasDisconnected()),this,SLOT(serverHasDisconnected()));
        //On connecte le signal de liste des joueurs
        connect(_client,SIGNAL(playerListHasBeenUpdated(QList<QPair<QString,bool> >)),this,SLOT(updatePlayerList(QList<QPair<QString,bool> >)));
        //On connecte le signal pour le début de partie
        connect(_client,SIGNAL(gameHasBegun()),this,SLOT(handleGameHasBegun()));
        //on affiche la fenêtre.
        QWidget::show();
    }
    /**
      * Ajoute un message dans le ListWidget
      */
    void WaitingWindow::addMessage(QString sender, QString contents)
    {
        _messages->addItem("<" + sender + "> " + contents);
    }
    /**
      * Appelé quand le serveur s'est déconnecté
      * ferme la fenêtre
      */
    void WaitingWindow::serverHasDisconnected()
    {
        //On affiche une jolie fenêtre indiquant que le serveur s'est déconnecté
        QMessageBox::critical(this,tr("Le serveur s'est déconnecté !"),tr("Le serveur s'est déconnecté !"));
        //On quitte la fenêtre.
        //TODO: Revenir au début.
        qApp->exit();
    }
    /**
      * Met à jour la liste des joueurs
      */
    void WaitingWindow::updatePlayerList(QList<QPair<QString, bool> > players)
    {
        //On déclare la QStringList
        QStringList list;
        for (int i = 0; i < players.size(); i++)
        {
            list << players[i].first;
        }
        //On l'ajoute au modele
        _playerList->setStringList(list);
    }
    /**
      * Gère le début de partie
      */
    void WaitingWindow::handleGameHasBegun()
    {
        hide();
        emit gameHasBegun();
    }
    /**
      * Appelé lors de l'appui sur une touche.
      * Gère l'envoi du message si on a appuyé sur "Entrée"
      */
    void WaitingWindow::keyPressEvent(QKeyEvent *event)
    {
        switch (event->key())
        {
            //Si on appuie sur Entrée, on envoie le message
            case Qt::Key_Return:
                sendMessageRequested();
                event->accept();
                return ;
            break;
        }
        event->ignore();
    }
}
