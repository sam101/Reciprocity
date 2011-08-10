#ifndef NETWORK_BUILDACCEPTEDMESSAGE_H
#define NETWORK_BUILDACCEPTEDMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du serveur au client, signalant que une construction a été acceptée.
      * @brief Signale qu'une construction a été acceptée
      * @author Sam101
      */
    class BuildAcceptedMessage
    {
        public:
            /**
              * MagicNumber de BuildAcceptedMessage
              */
            static const qint32 MAGICNUMBER_BUILD_ACCEPTED = 0x4218;
    };
}
#endif //NETWORK_BUILDACCEPTEDMESSAGE_H
