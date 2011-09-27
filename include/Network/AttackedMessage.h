#ifndef NETWORK_ATTACKEDMESSAGE_H
#define NETWORK_ATTACKEDMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message indiquant à un joueur qu'il a été attaqué par un autre joueur
      * @brief Message indiquant à un joueur qu'il a été attaqué par un autre joueur
      * @author Sam101
      */
    class AttackedMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de AttackedMessage
              */
            static const qint32 MAGICNUMBER_ATTACKED = 0x4225;
        protected:
            /**
              * Id de l'entité attaquée
              */
            qint32 _destId;
            /**
              * Id de l'entité attaquante
              */
            qint32 _sourceId;
        public:
            /**
              * Constructeur
              */
            AttackedMessage(qint32 destId = -1, qint32 sourceId = -1);
    };
}
#endif //NETWORK_ATTACKEDMESSAGE_H
