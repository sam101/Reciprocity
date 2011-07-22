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
        public:
            /**
              * Magic number de MessageOutMessage
              */
            static const qint32 MAGICNUMBER_MESSAGEOUTMESSAGE = 0x4208;
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
            /**
              * Constructeur
              */
            MessageOutMessage(QString contents, QString dest = "");
            /**
              * Renvoie le contenu du message
              */
            QString getContents() const;
            /**
              * Renvoie le destinataire du message
              */
            QString getDest() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const MessageOutMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, MessageOutMessage &m);
    };
}
#endif //NETWORK_MESSAGEOUTMESSAGE_H
