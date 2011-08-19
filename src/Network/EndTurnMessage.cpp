#include <Network/EndTurnMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    EndTurnMessage::EndTurnMessage(QString login) :
    AbstractMessage(Network::ENDTURN),
    _login(login)
    {

    }
    /**
      * Renvoie le login du joueur
      */
    QString EndTurnMessage::getLogin() const
    {
        return _login;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const EndTurnMessage &m)
    {
        out << m.MAGICNUMBER_ENDTURNMESSAGE;
        out << m._login;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, EndTurnMessage &m)
    {
        //On vérifie le MagicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_ENDTURNMESSAGE)
        {
            return in;
        }
        in >> m._login;
        return in;
    }

}
