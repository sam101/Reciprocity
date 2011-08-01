#ifndef NETWORK_BEGINGAMEMESSAGE_H
#define NETWORK_BEGINGAMEMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Envoyé du client au serveur pour demander le début de la partie
      * @brief Envoyé du client au serveur pour demander le début de la partie
      * @author Sam101
      */
    class BeginGameMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de BeginGameMessage
              */
            static const qint32 MAGICNUMBER_BEGINGAMEMESSAGE = 0x4210;
            /**
              * Constructeur
              */
            BeginGameMessage();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const BeginGameMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, BeginGameMessage &m);

    };
}
#endif //NETWORK_BEGINGAMEMESSAGE_H
