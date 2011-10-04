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
}
