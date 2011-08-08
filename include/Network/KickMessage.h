#ifndef NETWORK_KICKMESSAGE_H
#define NETWORK_KICKMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du serveur aux clients, signalant un kick de joueur
      * @brief Signale un kick de joueur
      * @author Sam101
      */
    class KickMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de KickMessage
              */
            static const qint32 MAGICNUMBER_KICK = 0x4205;
        protected:
            /**
              * Login du joueur qui a été kické
              */
            QString _login;
        public:
            /**
              * Constructeur
              */
            KickMessage(QString login = "");
            /**
              * Renvoie le login
              */
            QString getLogin() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const KickMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, KickMessage &m);
    };
}
#endif //NETWORK_KICKMESSAGE_H
