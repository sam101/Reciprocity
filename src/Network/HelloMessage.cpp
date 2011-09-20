#include <Network/HelloMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    HelloMessage::HelloMessage(QString name, qint32 version) :
    AbstractMessage(Network::HELLO),
    _name(name),
    _version(version)
    {

    }
}
