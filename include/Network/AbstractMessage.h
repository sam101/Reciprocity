#ifndef NETWORK_ABSTRACTMESSAGE_H
#define NETWORK_ABSTRACTMESSAGE_H
#include <Network/MessageType.h>
namespace Network
{
    /**
      * Classe de base pour un message envoyé sur le réseau
      * @brief Classe de base d'un message
      * @author Sam101
      */
    class AbstractMessage
    {
        protected:
            /**
              * Type du message
              */
            qint32 _type;
    };
}
#endif //NETWORK_ABSTRACTMESSAGE_H
