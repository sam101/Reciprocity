#ifndef NETWORK_KICKPLAYERMESSAGE_H
#define NETWORK_KICKPLAYERMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Envoyé d'un administrateur au serveur, pour ejecter un joueur de la partie
      * @brief Demande d'ejection d'un joueur de la partie d'un joueur au serveur.
      * @author Sam101
      */
    class KickPlayerMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de KickPlayerMessage
              */
            static const qint32 MAGICNUMBER_KICK_PLAYER = 0x4204;
        protected:
            /**
              * Login du joueur a ejecter
              */
            QString _login;
        public:
            /**
              * Constructeur
              */
            KickPlayerMessage(QString login = "");
            /**
              * Renvoie le login
              */
            QString getLogin() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const KickPlayerMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, KickPlayerMessage &m);
    };
}
#endif //NETWORK_KICKPLAYERMESSAGE_H
