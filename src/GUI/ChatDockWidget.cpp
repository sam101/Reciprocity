#include <GUI/ChatDockWidget.h>
#include <QtGui/QHBoxLayout>
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

}
