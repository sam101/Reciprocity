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
        _view->setScene(_scene);
    }
    /**
      * Destructeur
      */
    GameWindow::~GameWindow()
    {
        delete _view;
        delete _scene;
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
        //On affiche la fenêtre
        show();
        //On demande les informations de jeu
        _client->sendRequestData();
        //On connecte les signaux du dataHandler
        connect(_dataHandler,SIGNAL(chunkAdded(Chunk::Chunk*)),this,SLOT(addChunk(Chunk::Chunk*)));
        connect(_dataHandler,SIGNAL(chunkUpdated(Chunk::Chunk*)),this,SLOT(updateChunk(Chunk::Chunk*)));
    }
    /**
      * Ajoute un chunk
      */
    void GameWindow::addChunk(Chunk::Chunk *chunk)
    {
        _scene->addChunk(chunk);
    }
    /**
      * Met à jour un chunk
      */
    void GameWindow::updateChunk(Chunk::Chunk *chunk)
    {
        //TODO: Separer les deux
        _scene->addChunk(chunk);
    }
}
