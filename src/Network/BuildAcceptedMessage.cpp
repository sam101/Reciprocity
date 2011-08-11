#include <Network/BuildAcceptedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    BuildAcceptedMessage::BuildAcceptedMessage() :
    AbstractMessage(Network::BUILD_ACCEPTED)
    {

    }

    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const BuildAcceptedMessage &m)
    {
        //On envoie le magicNumber
        out << m.MAGICNUMBER_BUILD_ACCEPTED;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, BuildAcceptedMessage &m)
    {
        Q_UNUSED(m)
        //On recupère le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        //TODO: Vérification
        return in;
    }
}
