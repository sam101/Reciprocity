#ifndef NETWORK_REQUESTDATAMESSAGE_H
#define NETWORK_REQUESTDATAMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message de demande de données au serveur
      * Envoyé du client au serveur. Procède à la demande
      * des informations sur les chunk/entités auquelles le
      * client à accès
      * @brief Message de demande de données
      * @author Sam101
      */
    class RequestDataMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de RequestDataMessage
              */
            static const qint32 MAGICNUMBER_REQUEST_DATA = 0x4212;
            /**
              * Constructeur
              */
            RequestDataMessage();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const RequestDataMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, RequestDataMessage &m);
    };
}
#endif //NETWORK_REQUESTDATAMESSAGE_H
