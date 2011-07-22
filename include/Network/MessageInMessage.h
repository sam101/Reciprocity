#ifndef NETWORK_MESSAGEINMESSAGE_H
#define NETWORK_MESSAGEINMESSAGE_H
#include <QtCore/QString>
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Stocke un message envoyé du Serveur au Client
      * @brief Stocke un message envoyé du Serveur au Client
      * @author Sam101
      */
    class MessageInMessage : public AbstractMessage
    {
        public:
            /**
              * Magic number de MessageInMessage
              */
            static const qint32 MAGICNUMBER_MESSAGEINMESSAGE = 0x4209;
        protected:
            /**
              * Expéditeur du message
              */
            QString _sender;
            /**
              * Contenu du message
              */
            QString _contents;
       public:
            /**
              * Constructeur
              */
            MessageInMessage(QString sender = "", QString contents = "");
            /**
              * Renvoie l'expéditeur du message
              */
            QString getSender() const;
            /**
              * Renvoie le contenu du message
              */
            QString getContents() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const MessageInMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, MessageInMessage &m);
    };
}
#endif //NETWORK_MESSAGEINMESSAGE_H
