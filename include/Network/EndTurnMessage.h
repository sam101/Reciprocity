#ifndef NETWORK_ENDTURNMESSAGE_H
#define NETWORK_ENDTURNMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Gère l'envoi du message de "fin de tour" par un joueur
      * @brief Gère le message de fin de tour envoyé d'un joueur au serveur
      * @author Sam101
      */
    class EndTurnMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de EndTurnMessage
              */
            static const qint32 MAGICNUMBER_ENDTURNMESSAGE = 0x4222;
        protected:
            /**
              * Login du joueur qui a demandé la fin de tour
              */
            QString _login;
        public:
            /**
              * Constructeur
              */
            EndTurnMessage(QString login = "");
            /**
              * Renvoie le login du joueur
              */
            QString getLogin() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const EndTurnMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, EndTurnMessage &m);
    };
}
#endif //NETWORK_ENDTURNMESSAGE_H
