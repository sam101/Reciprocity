#ifndef NETWORK_ERRORMESSAGE_H
#define NETWORK_ERRORMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message d'erreur envoyé du serveur au client
      * @brief Message d'erreur envoyé du serveur au client
      * @author Sam101
      */
    class ErrorMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de ErrorMessage
              */
            static const qint32 MAGICNUMBER_ERRORMESSAGE = -0x4201;
        protected:
            /**
              * Intitulé du message d'erreur
              */
            QString _message;
       public:
            /**
              * Constructeur
              */
            ErrorMessage(QString message = "");
            /**
              * Renvoie l'intitulé du message d'erreur
              */
            QString getMessage() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const ErrorMessage &e);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, ErrorMessage &e);
    };
}
#endif //NETWORK_ERRORMESSAGE_H
