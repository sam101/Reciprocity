#include <Server/Server.h>
#include <QDebug>
namespace Server
{
    /**
      * Constructeur
      */
    Server::Server() :
    _socketServer(NULL),
    _clientHandler(NULL),
    _game(NULL)
    {
        //On initialise le ClientHandler.
        _clientHandler = new ClientHandler(_clients);
        //On initialise le MessageHandler
        _messageHandler = new MessageHandler(_clients);
        //On initialise le MessageSender
        _messageSender = new MessageSender(_clients);

        //On connecte entre eux le MessageHandler et le MessageSender
        connect(_messageHandler,SIGNAL(loginSuccess(QTcpSocket*,qint32,bool)),_messageSender,SLOT(sendLoginSuccess(QTcpSocket*,qint32,bool)));
        connect(_messageHandler,SIGNAL(loginAlreadyExists(QTcpSocket*,QString)),_messageSender,SLOT(sendLoginAlreadyExists(QTcpSocket*,QString)));
        connect(_messageHandler,SIGNAL(sendMessage(QString,QString,QString)),_messageSender,SLOT(sendChatMessage(QString,QString,QString)));
        connect(_messageHandler,SIGNAL(sendServerData(QTcpSocket*)),_messageSender,SLOT(sendServerData(QTcpSocket*)));
        connect(_messageHandler,SIGNAL(sendGameHasBegun(QTcpSocket*)),_messageSender,SLOT(sendGameHasBegun(QTcpSocket*)));
        connect(_messageHandler,SIGNAL(sendGameHasBegunToAll()),_messageSender,SLOT(sendGameHasBegunToAll()));
        connect(_messageHandler,SIGNAL(sendPlayerData(QTcpSocket*)),_messageSender,SLOT(sendPlayerData(QTcpSocket*)));
        connect(_messageHandler,SIGNAL(sendKickMessage(QString)),_messageSender,SLOT(sendKickMessage(QString)));
        connect(_messageHandler,SIGNAL(kickPlayer(QString)),_clientHandler,SLOT(kickPlayer(QString)));
        connect(_messageHandler,SIGNAL(entityMoved(QTcpSocket*,Map::Entity*)),_messageSender,SLOT(sendEntityHasMoved(QTcpSocket*,Map::Entity*)));
        connect(_messageHandler,SIGNAL(sendNewTurnToAll()),_messageSender,SLOT(sendNewTurnToAll()));
        connect(_messageHandler,SIGNAL(sendPlayerDataToAll()),_messageSender,SLOT(sendPlayerDataToAll()));
    }

    /**
      * Destructeur
      */
    Server::~Server()
    {
        if (_socketServer != NULL)
        {
            delete _socketServer;
        }
        delete _clientHandler;
        delete _messageHandler;
        if (_game != NULL)
        {
            delete _game;
        }
        //On détruit tout les Client
        QMutableMapIterator<QTcpSocket*,Client*> it(_clients);
        while (it.hasNext())
        {
            delete it.next();
        }
    }

    /**
      * Initialise le serveur
      */
    void Server::init(qint32 port)
    {
        //On initialise l'objet de jeu.
        if (_game != NULL)
        {
            delete _game;
        }
        _game = new Game::Game;
        //On indique que l'objet de jeu a changé.
        _messageHandler->setGame(_game);
        _messageSender->setGame(_game);
        //On détruit le socket précédent
        if (_socketServer != NULL)
        {
            _socketServer->close();
            delete _socketServer;
        }
        //On alloue l'objet
        _socketServer = new QTcpServer;
        //On commence à écouter les connexions entrantes
        if (!_socketServer->listen(QHostAddress::Any,port))
        {
            qFatal("Erreur: Impossible de commencer l'écoute sur le port");
        }
        qDebug() << "Début de l'écoute du serveur sur le port" << port;
        //On connecte les signaux au ClientHandler.
        connect(_socketServer,SIGNAL(newConnection()),_clientHandler,SLOT(handleIncomming()));
        connect(_clientHandler,SIGNAL(newClient(QTcpSocket*)),this,SLOT(newClient(QTcpSocket*)));
        //On connecte le signal pour le kick.
        connect(_messageHandler,SIGNAL(errorMessage(QTcpSocket*)),_clientHandler,SLOT(kickIncorrectClient(QTcpSocket*)));
    }
    /**
      * Ajoute un client à la liste des clients
      */
    void Server::newClient(QTcpSocket *socket)
    {
        if (_clients.contains(socket))
        {
            qDebug() << "Server::newClient: Erreur: le client existe déjà !";
            return;
        }
        //On crée l'objet Client
        _clients[socket] = new Client(socket);
        //On connecte le signal du socket au slot de MessageHandler
        connect(socket,SIGNAL(readyRead()),_messageHandler,SLOT(messageRecevied()));
    }
}
