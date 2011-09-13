#include <Network/WorkMessage.h>
namespace Network
{
    /**
      * Constructeur sans paramètres
      */
    WorkMessage::WorkMessage(qint32 entity) :
    AbstractMessage(Network::WORK),
    _entity(entity)
    {

    }
}
