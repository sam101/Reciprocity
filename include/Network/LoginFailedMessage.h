#ifndef NETWORK_LOGINFAILEDMESSAGE_H
#define NETWORK_LOGINFAILEDMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Stocke un message de type "Login Failed".
      * Ce message est envoyé du serveur au client pour lui indiquer
      * que son login a échoué
      */
    class LoginFailedMessage : public AbstractMessage
    {
        public:
            /**
              * Magic number de LoginFailedMessage
              */
            static const qint32 MAGICNUMBER_LOGINFAILEDMESSAGE = 0x4202;
            /**
              * Contient les types de possibilités existantes
              * pour qu'un login échoue
              */
            enum LoginFailedReasons
            {
                LOGIN_ALREADY_EXIST = 0,
                LOGIN_REJECTED = 1,
                WRONG_HASH = 2
            };

        protected:
            /**
              * Raison pour laquelle le login a echoué
              */
            qint32 _why;
       public:
            /**
              * Constructeur sans paramètres
              */
            LoginFailedMessage();
            /**
              * Constructeur
              */
            LoginFailedMessage(qint32 why = LOGIN_REJECTED);
            /**
              * Renvoie la raison pour laquelle le login a echoué
              */
            qint32 getWhy() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const LoginFailedMessage &l);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, LoginFailedMessage &l);
    };
}
#endif //NETWORK_LOGINFAILEDMESSAGE_H
