#include <Network/ServerDataMessage.h>
#include <QtCore/QDebug>
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
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const ServerDataMessage &m)
    {
        //On écrit le MagicNumber
        out << m.MAGICNUMBER_SERVER_DATA;
        //On écrit les données
        out << m._name;
        out << m._players;

        return out;
    }
    /**
      * Recupère le message d'un QDatastream
      */
    QDataStream& operator>>(QDataStream &in, ServerDataMessage &m)
    {
        //On recupère le MagicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_SERVER_DATA)
        {
            qDebug() << "Attention: message incorrect";
            return in;
        }
        //on recupère les données
        in >> m._name;
        in >> m._players;

        return in;
    }
}
