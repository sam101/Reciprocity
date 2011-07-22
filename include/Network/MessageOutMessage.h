#ifndef NETWORK_MESSAGEOUTMESSAGE_H
#define NETWORK_MESSAGEOUTMESSAGE_H
#include <QtCore/QString>
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message stockant un message envoyé par un joueur vers le serveur
      * @brief Stocke un message envoyé par un joueur vers le serveur
      * @author Sam101
      */
    class MessageOutMessage : public AbstractMessage
    {
        protected:
            /**
              * Contenu du message
              */
            QString _contents;
            /**
              * Destinataire du message.
              * Vide si tous
              */
            QString _dest;
        public:
            /**
              * Constructeur sans paramètres.
              */
            MessageOutMessage();
    };
}
#endif //NETWORK_MESSAGEOUTMESSAGE_H
