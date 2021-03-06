#include <GUI/GameWindow.h>
#include <QtGui/QApplication>
#include <Config/BaseConfig.h>
#include <Tools/ClientSettings.h>
#ifdef OPENGL_SUPPORT
#include <QtOpenGL/QGLWidget>
#endif
using namespace Config;
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
    _currentEntity(-1),
    _widgetShow(MAP)
    {
        //On connecte les signaux
        connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(saveWindowState()));
        //On restaure l'état de la fenêtre
        restoreState(ClientSettings::getValue("GameWindowState",QVariant()).toByteArray());
        restoreGeometry(ClientSettings::getValue("GameWindowGeometry").toByteArray());
        //On construit le widget principal et son layout
        QWidget *widget = new QWidget;
        _stack = new QStackedLayout;
        widget->setLayout(_stack);
        setCentralWidget(widget);
        //On initialise la vue
        _view = new QGraphicsView;
        //on active le support OpenGL si l'utilisateur l'a activé.
        #ifdef OPENGL_SUPPORT
        if (ClientSettings::getValue("videoMode","openGL").toString() == "openGL")
        {
            _view->setViewport(new QGLWidget);
        }
        #endif
        _stack->addWidget(_view);
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
        connect(_actionToolBar,SIGNAL(endTurnSelected()),this,SLOT(endTurn()));
        connect(_actionToolBar,SIGNAL(selectSelected()),this,SLOT(setSelect()));
        connect(_actionToolBar,SIGNAL(summarySelected()),this,SLOT(summaryRequested()));
        addToolBar(Qt::TopToolBarArea,_actionToolBar);
        addToolBarBreak(Qt::TopToolBarArea);
        //On initialise la ChooseToolBar
        _chooseToolBar = new ChooseToolBar;
        addToolBar(Qt::RightToolBarArea,_chooseToolBar);
        connect(_chooseToolBar,SIGNAL(moveRequested()),this,SLOT(setMove()));
        connect(_chooseToolBar,SIGNAL(buildRequested(Map::BuildingType)),this,SLOT(buildRequested(Map::BuildingType)));
        connect(_chooseToolBar,SIGNAL(workRequested()),this,SLOT(workRequested()));
        connect(_actionToolBar,SIGNAL(actionSelected()),_chooseToolBar,SLOT(showActions()));
        //On initialise le SummaryWidget
        _summaryWidget = new SummaryWidget;
        _stack->addWidget(_summaryWidget);
        _stack->setCurrentIndex(0);
        //On redimensione la fenêtre
        resize(BaseConfig::CHUNK_SIZE * BaseConfig::TILE_SIZE,BaseConfig::CHUNK_SIZE * BaseConfig::TILE_SIZE);
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
            _summaryWidget->setClient(c);
        }
    }
    /**
      * Change le numéro de tour actuel
      */
    void GameWindow::setTurn(qint32 turn)
    {
        //On change le numéro de tour dans le titre de la fenêtre
        setWindowTitle(tr("Reciprocity - Tour ") + QString::number(turn) + ".");
        //On réactive le bouton "Fin de tour"
        _actionToolBar->enableEndTurn();
        //On affiche un message dans le ChatDockWidget
        _chatDock->newTurnMessage(turn);
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
        connect(_client,SIGNAL(turnNumberHasChanged(qint32)),this,SLOT(setTurn(qint32)));
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
        _summaryWidget->updateEntityList();
    }
    /**
      * Met à jour une entité
      */
    void GameWindow::updateEntity(Map::Entity *entity)
    {
        _scene->updateEntity(entity);
        _summaryWidget->updateEntityList();
    }
    /**
      * Appelé quand une tile a été selectionnée.
      * Transmet l'information à ActionBar pour
      * changer l'indic.
      */
    void GameWindow::tileSelected(qint32 x, qint32 y)
    {
        //On affiche la tile
        _actionToolBar->displayTile(_dataHandler->getTile(x,y));
        //On affiche le batiment
        _actionToolBar->displayBuilding(_dataHandler->getBuilding(x,y),_dataHandler->getTile(x,y));
        //On recupère l'entité
        Map::Entity *e = _dataHandler->getEntityByCoordinates(x,y);
        if (e == NULL || e->getOwner() != _client->getId())
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
        //On remet à zéro la selection dans ActionToolBar
        _actionToolBar->resetSelection();
    }
    /**
      * Appelé quand une demande de construction a été faite
      */
    void GameWindow::buildRequested(Map::BuildingType type)
    {
        if (_currentEntity < 0)
        {
            return;
        }
        //On envoie le message de construction
        _client->sendBuild(_currentEntity,type);
        //On ferme la ChooseToolBar
        _chooseToolBar->showNothing();
    }
    /**
      * Appelé quand une demande de travail est faite
      */
    void GameWindow::workRequested()
    {
        if (_currentEntity < 0)
        {
            return;
        }
        //On envoie le message de travail
        _client->sendWork(_currentEntity);
        //On ferme la ChooseToolBar
        _chooseToolBar->showNothing();
    }
    /**
      * Appelé quand l'utilisateur souhaite voir le récapitulatif
      */
    void GameWindow::summaryRequested()
    {
        //Si on est sur la vue "Résumé", on passe à la vue carte
        if (_widgetShow == SUMMARY)
        {
            _stack->setCurrentIndex(0);
            _widgetShow = MAP;
        }
        //Si on est sur la vue carte, on passe à la vue résumé
        else
        {
            _stack->setCurrentIndex(1);
            _widgetShow = SUMMARY;
        }
    }
    /**
      * Appelé quand le joueur veut finir son tour
      */
    void GameWindow::endTurn()
    {
        //On envoie au serveur la demande de fin de tour
        _client->sendEndTurn();
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
