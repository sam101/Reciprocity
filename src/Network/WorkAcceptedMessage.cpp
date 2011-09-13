#include <Network/WorkAcceptedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    WorkAcceptedMessage::WorkAcceptedMessage(qint32 entity) :
    AbstractMessage(MAGICNUMBER_WORK_ACCEPTED),
    _entity(entity)
    {

    }
}
