#ifndef NETWORK_GETSERVERDATAMESSAGE_H
#define NETWORK_GETSERVERDATAMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du client au serveur demandant les informations sur le serveur
      * @brief Message envoyé du client au serveur demandant les informations sur le serveur
      * @author Sam101
      */
    class GetServerDataMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de GetServerDataMessage
              */
            static const qint32 MAGICNUMBER_GET_SERVER_DATA = 0x4206;
        public:
            /**
              * Constructeur
              */
            GetServerDataMessage();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const GetServerDataMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, GetServerDataMessage &m);
    };
}
#endif //NETWORK_GETSERVERDATAMESSAGE_H
