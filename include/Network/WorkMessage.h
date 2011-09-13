#ifndef NETWORK_WORKMESSAGE_H
#define NETWORK_WORKMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    class WorkMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de WorkMessage
              */
            static const qint32 MAGICNUMBER_WORK = 0x4219;
        protected:
            /**
              * Entité qui doit travailler
              */
            qint32 _entity;
        public:
            /**
              * Constructeur
              */
            WorkMessage(qint32 entity = -1);
    };
}
#endif //NETWORK_WORKMESSAGE_H
