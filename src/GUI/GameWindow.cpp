#include <GUI/GameWindow.h>
namespace GUI
{
    /**
      * Constructeur
      */
    GameWindow::GameWindow() :
    _client(NULL),
    _dataHandler(NULL),
    _view(NULL),
    _scene(NULL)
    {
       //On initialise la vue
        _view = new QGraphicsView;
       //On initialise la scène.
        _scene = new GameScene;
    }
    /**
      * Change l'objet client actuel
      */
    void GameWindow::setClient(QObject *client)
    {
        Client::Client *c = qobject_cast<Client::Client*>(client);
        if (c != NULL)
        {
            _client = c;
            _dataHandler = _client->getDataHandler();
        }
    }
    /**
      * Commence la partie
      */
    void GameWindow::beginGame()
    {
        show();
    }
}
