#include <Network/KickPlayerMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    KickPlayerMessage::KickPlayerMessage(QString login) :
    AbstractMessage(Network::KICK_PLAYER),
    _login(login)
    {

    }
    /**
      * Renvoie le login
      */
    QString KickPlayerMessage::getLogin() const
    {
        return _login;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const KickPlayerMessage &m)
    {
        //On envoie le magicNumber
        out << m.MAGICNUMBER_KICK_PLAYER;
        //On envoie les données
        out << m._login;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, KickPlayerMessage &m)
    {
        //On recupère le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_KICK_PLAYER)
        {
            return in;
        }
        //On recupère les données
        in >> m._login;

        return in;
    }
}
