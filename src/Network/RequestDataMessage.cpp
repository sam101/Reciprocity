#include <Network/RequestDataMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    RequestDataMessage::RequestDataMessage() :
    AbstractMessage(Network::REQUEST_DATA)
    {

    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const RequestDataMessage &m)
    {
        out << m.MAGICNUMBER_REQUEST_DATA;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, RequestDataMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;
        //TODO: Verification
        return in;
    }

}
