#ifndef NETWORK_NEWTURNMESSAGE_H
#define NETWORK_NEWTURNMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du serveur au client, indiquant qu'un nouveau tour est en cours
      * @brief Indique nouveau tour
      * @author Sam101
      */
    class NewTurnMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de NewTurnMessage
              */
            static const qint32 MAGICNUMBER_NEWTURN = 0x4223;
        protected:
            /**
              * Numéro du tour
              */
            qint32 _turn;
        public:
            /**
              * Constructeur
              */
            NewTurnMessage(qint32 turn = 0);
            /**
              * Renvoie le numéro du tour
              */
            qint32 getTurn() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const NewTurnMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, NewTurnMessage &m);
    };
}
#endif //NETWORK_NEWTURNMESSAGE_H
