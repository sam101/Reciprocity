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
    };
}
#endif //NETWORK_LOGINSUCCESSMESSAGE_H
