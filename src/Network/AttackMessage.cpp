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
    qint32 AttackMessage::getId() const
    {
        return _id;
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
}
