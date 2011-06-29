#ifndef NETWORK_ABSTRACTMESSAGE_H
#define NETWORK_ABSTRACTMESSAGE_H
#include <QtCore/Qt>
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
        public:
            /**
              * Constructeur
              */
            AbstractMessage(qint32 type);
            /**
              * Renvoie le type du message
              */
            qint32 getType() const;
    };
}
#endif //NETWORK_ABSTRACTMESSAGE_H
