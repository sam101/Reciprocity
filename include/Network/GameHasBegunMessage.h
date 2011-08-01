#ifndef NETWORK_GAMEHASBEGUNMESSAGE_H
#define NETWORK_GAMEHASBEGUNMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message signalant au joueur que la partie à commencé.
      * @brief Message signalant au joueur que la partie à commencé.
      * @author Sam101
      */
    class GameHasBegunMessage : public AbstractMessage
    {
        protected:

        public:
            /**
              * MagicNumber de GameHasBegunMessage
              */
            static const qint32 MAGICNUMBER_GAMEHASBEGUN = 0x4211;
            /**
              * Constructeur
              */
            GameHasBegunMessage();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const GameHasBegunMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, GameHasBegunMessage &m);
    };
}
#endif //NETWORK_GAMEHASBEGUNMESSAGE_H
