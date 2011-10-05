#include <Network/DeleteMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    DeleteMessage::DeleteMessage(DeleteType type, qint32 x, qint32 y, qint32 entityId) :
    AbstractMessage(Network::DELETE),
    _type(type),
    _x(x),
    _y(y),
    _entityId(entityId)
    {

    }
    /**
      * Renvoie la position X
      */
    qint32 DeleteMessage::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y
      */
    qint32 DeleteMessage::getY() const
    {
        return _y;
    }
    /**
      * Renvoie l'id de l'entité à détruire
      */
    qint32 DeleteMessage::getEntityId() const
    {
        return _entityId;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const DeleteMessage &m)
    {
        out << m.MAGICNUMBER_DELETE;
        out << (qint32)m._type;
        out << m._x;
        out << m._y;
        out << m._entityId;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, DeleteMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;
        in >> (qint32&)m._type;

        return in;
    }
}
