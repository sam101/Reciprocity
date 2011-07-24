#include <Network/ServerDataMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    ServerDataMessage::ServerDataMessage(QString name) :
    AbstractMessage(Network::SERVER_DATA),
    _name(name)
    {

    }
    /**
      * Ajoute un joueur à la liste des joueurs
      */
    void ServerDataMessage::addPlayer(QString login, bool isAdmin)
    {
        _players.append(QPair<QString,bool>(login,isAdmin));
    }
    /**
      * Renvoie la liste des joueurs
      */
    const QList<QPair<QString,bool> >& ServerDataMessage::getPlayers() const
    {
        return _players;
    }
}
