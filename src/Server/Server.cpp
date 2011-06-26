#include <Server/Server.h>
namespace Server
{
    /**
      * Constructeur
      */
    Server::Server(qint32 port) :
    _socketServer(NULL),
    _game(NULL)
    {
        init(port);
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
        _socketServer->listen(QHostAddress::Any,port);
    }
}
