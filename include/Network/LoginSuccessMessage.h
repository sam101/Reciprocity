#ifndef NETWORK_LOGINSUCCESSMESSAGE_H
#define NETWORK_LOGINSUCCESSMESSAGE_H
#include <QtCore/Qt>
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Stocke un message de type "Login Réussi"
      * @brief Stocke un message de type "Login réussi"
      * @author Sam101
      */
    class LoginSuccessMessage : public AbstractMessage
    {
        public:
            /**
              * Magic number de LoginSuccessMessage
              */
            static const qint32 MAGICNUMBER_LOGINSUCCESSMESSAGE = 0x4203;
        protected:
            /**
              * Id du client après login.
              */
            qint32 _id;
        public:
            /**
              * Constructeur
              */
            LoginSuccessMessage(qint32 id);
            /**
              * Renvoie l'id
              */
            qint32 getId() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const LoginSuccessMessage &l);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, LoginSuccessMessage &l);
    };
}
#endif //NETWORK_LOGINSUCCESSMESSAGE_H
