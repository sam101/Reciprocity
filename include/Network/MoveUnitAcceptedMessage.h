#ifndef NETWORK_MOVEUNITACCEPTED_H
#define NETWORK_MOVEUNITACCEPTED_H
#include <Network/AbstractMessage.h>
namespace Network
{
    class MoveUnitAcceptedMessage
    {
        public:
            /**
              * MagicNumber de MoveUnitAcceptedMessage
              */
            static const qint32 MAGICNUMBER_MOVEUNIT_ACCEPTED = 0x4216;
    };
}
#endif //NETWORK_MOVEUNITACCEPTED_H
