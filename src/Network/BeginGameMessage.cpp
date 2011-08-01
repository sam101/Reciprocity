#include <Network/BeginGameMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    BeginGameMessage::BeginGameMessage() :
    AbstractMessage(Network::BEGIN_GAME)
    {

    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const BeginGameMessage &m)
    {
        //On envoie le Magicnumber
        out << m.MAGICNUMBER_BEGINGAMEMESSAGE;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, BeginGameMessage &m)
    {
        Q_UNUSED(m)
        //TODO
        qint32 magicNumber;
        in >> magicNumber;
        return in;
    }
}
