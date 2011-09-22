#include <GUI/ChatDockWidget.h>
#include <QtGui/QHBoxLayout>
#include <QtGui/QKeyEvent>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
namespace GUI
{
    /**
      * Constructeur
      */
    ChatDockWidget::ChatDockWidget() :
    _client(NULL)
    {
        setObjectName("ChatDockWidget");
        //On indique ce que peux faire le ChatDockWidget
        setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
        //On construit le widget
        QWidget *widget = new QWidget;
        //On construit le layout du widget
        QVBoxLayout *layout = new QVBoxLayout;
        layout->setMargin(0);
        widget->setLayout(layout);
        //On construit la liste des messages
        _messages = new QListWidget;
        layout->addWidget(_messages);
        //On construit la ligne du texte
        QHBoxLayout *h = new QHBoxLayout;
        layout->addLayout(h);
        _text = new QLineEdit;
        h->addWidget(_text);
        //On redimensionne
        setWidget(widget);
        //On met le premier message
        _messages->addItem(tr("Vous avez rejoint la partie"));
    }
    /**
      * Change l'objet client actuel
      */
    void ChatDockWidget::setClient(Client::Client *client)
    {
        _client = client;
        connect(_client,SIGNAL(messageRecevied(QString,QString)),this,SLOT(messageRecevied(QString,QString)));

    }
    /**
      * Appelé à la reception d'un message
      * Ajoute un message
      */
    void ChatDockWidget::messageRecevied(QString sender, QString contents)
    {
        _messages->addItem("<" + sender + ">" + contents);
    }
    /**
      * Ajoute le message de nouveau tour dans le ChatDock
      */
    void ChatDockWidget::newTurnMessage(qint32 turnId)
    {
        _messages->addItem(tr("Début du tour ") + QString::number(turnId));
    }
    /**
      * Appelé lors de l'appui sur une touche.
      * Gère l'envoi du message
      */
    void ChatDockWidget::keyPressEvent(QKeyEvent *event)
    {
        //Si le joueur a appuyé sur entrée
        if (event->key() == Qt::Key_Return)
        {
            //On envoie le texte
            _client->sendChatMessage(_text->text());
            //On remet le texte à zéro
            _text->setText("");
            //On accepte l'evenement
            event->accept();
            return;
        }
        event->ignore();
    }
}
