#include <Network/AttackMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    AttackMessage::AttackMessage(qint32 entityId, qint32 x, qint32 y) :
    AbstractMessage(Network::ATTACK),
    _entityId(entityId),
    _x(x),
    _y(y)
    {

    }
    /**
      * Renvoie l'id de l'entité
      */
    qint32 AttackMessage::getEntityId() const
    {
        return _entityId;
    }
    /**
      * Renvoie la position X à attaquer
      */
    qint32 AttackMessage::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y à attaquer
      */
    qint32 AttackMessage::getY() const
    {
        return _y;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const AttackMessage &m)
    {
        out << m.MAGICNUMBER_ATTACK;
        out << m._entityId;
        out << m._x;
        out << m._y;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, AttackMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;

        in >> m._entityId;
        in >> m._x;
        in >> m._y;

        return in;
    }
}
