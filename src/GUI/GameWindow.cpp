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
    _scene(NULL),
    _currentEntity(-1)
    {
        //On connecte les signaux
        connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(saveWindowState()));
        //On restaure l'état de la fenêtre
        restoreState(ClientSettings::getValue("GameWindowState",QVariant()).toByteArray());
        restoreGeometry(ClientSettings::getValue("GameWindowGeometry").toByteArray());
        //On initialise la vue
        _view = new QGraphicsView;
        setCentralWidget(_view);
        //On initialise la scène.
        _scene = new GameScene;
        connect(_scene,SIGNAL(moveRequested(qint32,qint32)),this,SLOT(moveSelected(qint32,qint32)));
        connect(_scene,SIGNAL(tileSelected(qint32,qint32)),this,SLOT(tileSelected(qint32,qint32)));
        _view->setScene(_scene);
        //On initialise le chatDockWidget
        _chatDock = new ChatDockWidget;
        addDockWidget(Qt::BottomDockWidgetArea,_chatDock);
        //On initialise le ActionsDock
        _actionToolBar = new ActionToolBar;
        connect(_actionToolBar,SIGNAL(moveSelected()),this,SLOT(setMove()));
        connect(_actionToolBar,SIGNAL(selectSelected()),this,SLOT(setSelect()));
        addToolBar(Qt::TopToolBarArea,_actionToolBar);
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
            _actionToolBar->setDataHandler(_dataHandler);
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
        connect(_dataHandler,SIGNAL(entityUpdated(Map::Entity*)),this,SLOT(updateEntity(Map::Entity*)));
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
    /**
      * Met à jour une entité
      */
    void GameWindow::updateEntity(Map::Entity *entity)
    {
        _scene->updateEntity(entity);
    }

    /**
      * Appelé quand une tile a été selectionnée.
      * Transmet l'information à ActionBar pour
      * changer l'indic.
      */
    void GameWindow::tileSelected(qint32 x, qint32 y)
    {
        _actionToolBar->displayTile(_dataHandler->getTile(x,y));
         Map::Entity *e = _dataHandler->getEntityByCoordinates(x,y);
         if (e == NULL)
         {
             //On désactive les actions sur entité
             _currentEntity = -1;
             _scene->setEntitySelected(false);
         }
         else
         {
             //On met à jour l'entité selectionnée sinon
             _currentEntity = e->getId();
             _scene->setEntitySelected(true);
         }
         _actionToolBar->displayEntity(e);
    }
    /**
      * Appelé quand une demande de mouvement d'unité a été envoyée
      */
    void GameWindow::moveSelected(qint32 x, qint32 y)
    {
        qDebug() << "Demande de déplacement de l'entité" << _currentEntity << "en" << x << y;
        //On vérifie qu'on a bien selectionné une entité
        if (_currentEntity < 0)
        {
            return;
        }
        //On vérifie que l'entité existe
        Map::Entity *e = _client->getDataHandler()->getEntity(_currentEntity);
        if (e == NULL)
        {
            return;
        }
        //On fait bouger l'entité par le client
        _client->sendMoveUnit(_currentEntity,x - e->getX() ,y - e->getY());
        //On enlève la selection actuelle
        _currentEntity = -1;
    }

    /**
      * Change le type actuel de selection pour "Selectionner"
      */
    void GameWindow::setSelect()
    {
        _currentEntity = -1;
        _scene->setActionType(SELECT);
    }
    /**
      * Change le type actuel de selection pour "Se déplacer"
      */
    void GameWindow::setMove()
    {
        _scene->setActionType(MOVE);
    }
}
