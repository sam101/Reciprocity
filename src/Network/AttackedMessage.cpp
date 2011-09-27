#include <Network/AttackedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    AttackedMessage::AttackedMessage(qint32 destId, qint32 sourceId) :
    AbstractMessage(Network::ATTACKED),
    _destId(destId),
    _sourceId(sourceId)
    {

    }
    /**
      * Renvoie l'id de l'entité attaquée
      */
    qint32 AttackedMessage::getDestId() const
    {
        return _destId;
    }
    /**
      * Renvoie l'id de l'entité attaquante
      */
    qint32 AttackedMessage::getSourceId() const
    {
        return _sourceId;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const AttackedMessage &m)
    {
        out << m.MAGICNUMBER_ATTACKED;
        out << m._destId;
        out << m._sourceId;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, AttackedMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;

        in >> m._destId;
        in >> m._sourceId;

        return in;
    }
}
