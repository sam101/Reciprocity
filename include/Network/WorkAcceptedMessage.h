#ifndef NETWORK_WORKACCEPTEDMESSAGE_H
#define NETWORK_WORKACCEPTEDMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message indiquant qu'un travail d'une entité a été accepté
      * @brief Indique qu'un travail d'une entité a été accepté
      * @author Sam101
      */
    class WorkAcceptedMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de WorkAcceptedMessage
              */
            static const qint32 MAGICNUMBER_WORK_ACCEPTED = 0x4220;
        protected:
            /**
              * Entité dont le travail a été accepté
              */
            qint32 _entity;
           public:
            /**
              * Constructeur
              */
            WorkAcceptedMessage(qint32 entity = -1);
    };
}
#endif //NETWORK_WORKACCEPTEDMESSAGE_H
