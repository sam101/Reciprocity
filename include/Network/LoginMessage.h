#ifndef NETWORK_LOGINMESSAGE_H
#define NETWORK_LOGINMESSAGE_H
#include <QtCore/QString>
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Stocke un message de type "Login", envoyé du client au serveur
      * @brief Stocke un message de type "Login"
      * @author Sam101
      */
    class LoginMessage : public AbstractMessage
    {
        public:
            /**
              * Magic number de LoginMessage
              */
            static const qint32 MAGICNUMBER_LOGINMESSAGE = 0x4201;
        protected:
            /**
              * Numéro de version du client
              */
            qint32 _version;
            /**
              * Login que le client veut utiliser
              */
            QString _login;
            /**
              * Hash que le client veut utiliser
              */
            QString _hash;
        public:
            /**
              * Constructeur sans paramètres
              */
            LoginMessage();
            /**
              * Constructeur
              */
            LoginMessage(qint32 version, QString login, QString hash);
           /**
             * Renvoie le login à utiliser
             */
            QString getLogin() const;
            /**
              * Renvoie le hash à utiliser
              */
            QString getHash() const;
            /**
              * Envoie le LoginMessage dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const LoginMessage &l);
            /**
              * Recupère un LoginMessage d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, LoginMessage &l);
    };
}
#endif //NETWORK_LOGINMESSAGE_H
