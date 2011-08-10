#ifndef NETWORK_BUILDMESSAGE_H
#define NETWORK_BUILDMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Envoyé du client au serveur, demande de construction d'un
      * batiment
      * @brief Demande de construction d'un batiment
      * @author Sam101
      */
    class BuildMessage
    {
        public:
            /**
              * MagicNumber de BuildMessage
              */
            static const qint32 MAGICNUMBER_BUILD = 0x4217;
    };
}
#endif //NETWORK_BUILDMESSAGE_H
