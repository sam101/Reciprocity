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
}
