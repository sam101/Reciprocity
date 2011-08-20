#include <GUI/GameScene.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
#include <QtGui/QKeyEvent>
#include <QtGui/QGraphicsSceneMouseEvent>
namespace GUI
{
    /**
      * Constructeur
      */
    GameScene::GameScene() :
    _dataHandler(NULL),
    _xCamera(0),
    _yCamera(0),
    _tileX(0),
    _tileY(0),
    _entitySelected(false),
    _actionType(SELECT)
    {
        //On met le fond en noir.
        setBackgroundBrush(Qt::black);
        //On gère la caméra
        updateSceneRect();
    }
    /**
      * Change l'état si une entité est selectionnée ou non
      */
    void GameScene::setEntitySelected(bool entitySelected)
    {
        _entitySelected = entitySelected;
    }
    /**
      * Change l'ActionType actuel
      */
    void GameScene::setActionType(ActionType type)
    {
        _actionType = type;
    }

    /**
      * Ajoute/met à jour un chunk
      */
    void GameScene::addChunk(Chunk::Chunk *chunk)
    {
        if (_tiles.contains(Coordinate(chunk->getX(),chunk->getY())))
        {
            _tiles[Coordinate(chunk->getX(),chunk->getY())]->setChunk(chunk);
            _buildings[Coordinate(chunk->getX(),chunk->getY())]->setChunk(chunk);
        }
        //On ajoute le TileChunkItem
        TileChunkItem *t = new TileChunkItem(chunk);
        _tiles[Coordinate(chunk->getX(),chunk->getY())] = t;
        addItem(t);
        //On ajoute le BuildingChunkItem
        BuildingChunkItem *b = new BuildingChunkItem(chunk);
        _buildings[Coordinate(chunk->getX(),chunk->getY())] = b;
        addItem(b);
        //On change la caméra
        _xCamera = chunk->getX();
        _yCamera = chunk->getY();
        updateSceneRect();

    }
    /**
      * Ajoute une entité
      */
    void GameScene::addEntity(Map::Entity *entity)
    {
        if (_entities.contains(entity->getId()))
        {
            return;
        }
        //On ajoute le EntityItem
        EntityItem *e = new EntityItem(entity);
        _entities[entity->getId()] = e;
        addItem(e);
        //On change la caméra
        _xCamera = entity->getX();
        _yCamera = entity->getY();
        updateSceneRect();

    }
    /**
      * Met à jour une entité
      */
    void GameScene::updateEntity(Map::Entity *entity)
    {
        if (_entities.contains(entity->getId()))
        {
            _entities[entity->getId()]->updateEntity(entity);
        }
        else
        {
            qDebug() << "Warning: L'entité a mettre à jour n'existe pas";
        }
    }

    /**
      * Appelé à l'appui sur une touche.
      * Bouge la caméra.
      */
    void GameScene::keyPressEvent(QKeyEvent *event)
    {
        //On gère selon la touche
        switch (event->key())
        {
            case Qt::Key_Up:
                _yCamera--;
            break;
            case Qt::Key_Down:
                _yCamera++;
            break;
            case Qt::Key_Left:
                _xCamera--;
            break;
            case Qt::Key_Right:
                _xCamera++;
            break;

        }
        //On change la caméra.
        updateSceneRect();
    }
    /**
      * Appelé au clic de la souris
      */
    void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        mouseMoveEvent(event);
    }

    /**
      * Appelé au déplacement de la souris
      */
    void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        qint32 x = event->scenePos().x() / Config::Config::TILE_SIZE;
        if (x <= 0) x--;
        qint32 y = event->scenePos().y() / Config::Config::TILE_SIZE;
        if (y <= 0) y--;
        //On envoie pas le signal si la tile n'a pas changé.
        if (x == _tileX && y == _tileY)
        {
            return;
        }

        //Si le joueur a fait un clic droit, on le compte comme une demande de déplacement
        if (event->buttons() == Qt::RightButton || event->button() == Qt::RightButton)
        {
            emit moveRequested(x,y - 1);
        }
        else
        {
            switch(_actionType)
            {
                //On gère le déplacement
                case SELECT:
                    //On change les coordonnées actuelles
                    _tileX = x;
                    _tileY = y;
                    emit tileSelected(x,y - 1);
                break;
                case MOVE:
                    _actionType = SELECT;
                    emit moveRequested(x,y - 1);
                default:
                    //On change les coordonnées actuelles
                    _tileX = x;
                    _tileY = y;
                    emit tileSelected(x,y - 1);
            }

        }
        event->accept();
    }
    /**
      * Remet à jour les coordonnées du sceneRect
      */
    void GameScene::updateSceneRect()
    {
        setSceneRect(_xCamera * Config::Config::TILE_SIZE,_yCamera * Config::Config::TILE_SIZE,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2,Config::Config::CHUNK_SIZE * Config::Config::TILE_SIZE / 2);
    }
}
