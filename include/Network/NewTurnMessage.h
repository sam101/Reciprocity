#ifndef NETWORK_NEWTURNMESSAGE_H
#define NETWORK_NEWTURNMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    class NewTurnMessage
    {
        public:
            /**
              * MagicNumber de NewTurnMessage
              */
            static const qint32 MAGICNUMBER_NEWTURN = 0x4222;
        protected:


    };
}
#endif //NETWORK_NEWTURNMESSAGE_H
