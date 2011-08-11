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
    class BuildAcceptedMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de BuildAcceptedMessage
              */
            static const qint32 MAGICNUMBER_BUILD_ACCEPTED = 0x4218;
            /**
              * Constructeur
              */
            BuildAcceptedMessage();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const BuildAcceptedMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, BuildAcceptedMessage &m);
    };
}
#endif //NETWORK_BUILDACCEPTEDMESSAGE_H
