#include <Server/Server.h>
#include <QDebug>
namespace Server
{
    /**
      * Constructeur
      */
    Server::Server(qint32 port) :
    _socketServer(NULL),
    _clientHandler(NULL),
    _game(NULL)
    {
        //On initialise le ClientHandler.
        _clientHandler = new ClientHandler;
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
        if (_game != NULL)
        {
            delete _game;
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
        qDebug() << "Début de l'écoute du serveur";
        //On connecte les signaux au ClientHandler.
        connect(_socketServer,SIGNAL(newConnection()),_clientHandler,SLOT(handleIncomming()));
    }
}
