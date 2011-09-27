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
}
