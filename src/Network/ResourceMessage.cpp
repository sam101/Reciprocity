#include <Network/ResourceMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    ResourceMessage::ResourceMessage(MoveType type, qint32 entityId, qint32 entityIdDest) :
    AbstractMessage(Network::RESOURCE),
    _type(type),
    _entityId(entityId),
    _entityIdDest(entityIdDest)
    {

    }
    /**
      * Renvoie le type de déplacement
      */
    ResourceMessage::MoveType ResourceMessage::getType() const
    {
        return _type;
    }
    /**
      * Renvoie l'id de l'entité source
      */
    qint32 ResourceMessage::getEntityId() const
    {
        return _entityId;
    }
    /**
      * Renvoie l'id de l'entité destination
      */
    qint32 ResourceMessage::getEntityIdDest() const
    {
        return _entityIdDest;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const ResourceMessage &m)
    {
        out << m.MAGICNUMBER_RESOURCE;
        out << (qint8)m._type;
        out << m._entityId;
        out << m._entityIdDest;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, ResourceMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;
        in >> (qint8&)m._type;
        in >> m._entityId;
        in >> m._entityIdDest;

        return in;
    }
}

