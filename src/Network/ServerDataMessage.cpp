#include <Network/ServerDataMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    ServerDataMessage::ServerDataMessage() :
    AbstractMessage(Network::SERVER_DATA)
    {

    }
    /**
      * Ajoute un joueur à la liste des joueurs
      */
    void ServerDataMessage::addPlayer(QString login, bool isAdmin)
    {
        _players.append(QPair<QString,bool>(login,isAdmin));
    }
}
