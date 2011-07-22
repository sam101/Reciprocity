#include <GUI/WaitingWindow.h>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
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
        h2->addWidget(send,2);
    }
}
