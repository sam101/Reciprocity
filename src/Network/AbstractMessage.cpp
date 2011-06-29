#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    AbstractMessage::AbstractMessage(qint32 type) :
    _type(type)
    {

    }
    /**
      * Renvoie le type du message
      */
    qint32 AbstractMessage::getType() const
    {
        return _type;
    }
}
