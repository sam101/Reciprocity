#include <Network/KickMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    KickMessage::KickMessage(QString login) :
    AbstractMessage(Network::KICK),
    _login(login)
    {

    }
    /**
      * Renvoie le login
      */
    QString KickMessage::getLogin() const
    {
        return _login;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const KickMessage &m)
    {
        //On envoie le magicNumber
        out << m.MAGICNUMBER_KICK;
        //On envoie les données
        out << m._login;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, KickMessage &m)
    {
        //On recupère le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_KICK)
        {
            return in;
        }
        //On recupère les données
        in >> m._login;

        return in;
    }
}
