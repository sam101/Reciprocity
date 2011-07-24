#include <Network/GetServerDataMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    GetServerDataMessage::GetServerDataMessage() :
    AbstractMessage(Network::GET_SERVER_DATA)
    {

    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const GetServerDataMessage &m)
    {
        out << m.MAGICNUMBER_GET_SERVER_DATA;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, GetServerDataMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;
        //TODO: Vérification
        return in;
    }
}
