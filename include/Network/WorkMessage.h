#ifndef NETWORK_WORKMESSAGE_H
#define NETWORK_WORKMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message demandant à une entité de travailler
      * @brief Message demandant à une entité de travailler
      * @author Sam101
      */
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
            /**
              * Renvoie l'entité qui doit travailler
              */
            qint32 getEntity() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const WorkMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, WorkMessage &m);
    };
}
#endif //NETWORK_WORKMESSAGE_H
