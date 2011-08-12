#include <GUI/GameWindow.h>
#include <QtGui/QApplication>
#include <Tools/ClientSettings.h>
using namespace Tools;
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
        connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(saveWindowState()));
        //On restaure l'état de la fenêtre
        restoreState(ClientSettings::getValue("GameWindowState",QVariant()).toByteArray());
        restoreGeometry(ClientSettings::getValue("GameWindowGeometry").toByteArray());
        //On initialise la vue
        _view = new QGraphicsView;
        setCentralWidget(_view);
        //On initialise la scène.
        _scene = new GameScene;
        _view->setScene(_scene);
        //On initialise le chatDockWidget
        _chatDock = new ChatDockWidget;
        addDockWidget(Qt::BottomDockWidgetArea,_chatDock);
        //On initialise le ActionsDock
        _actionsDock = new ActionToolBar;
        addToolBar(Qt::TopToolBarArea,_actionsDock);
        //On redimensione la fenêtre
        resize(Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE);
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
            _chatDock->setClient(c);
            _dataHandler = _client->getDataHandler();
        }
    }
    /**
      * Sauvegarde l'état de la fenêtre
      */
    void GameWindow::saveWindowState()
    {
        ClientSettings::setValue("GameWindowGeometry",saveGeometry());
        ClientSettings::setValue("GameWindowState",saveState());
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
        connect(_dataHandler,SIGNAL(entityAdded(Map::Entity*)),this,SLOT(addEntity(Map::Entity*)));
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
    /**
      * Ajoute une entité
      */
    void GameWindow::addEntity(Map::Entity *entity)
    {
        _scene->addEntity(entity);
    }
}
