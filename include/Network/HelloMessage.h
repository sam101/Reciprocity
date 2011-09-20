#ifndef NETWORK_HELLOMESSAGE_H
#define NETWORK_HELLOMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du serveur au client envoyant les infos de base du serveur
      * @brief Message envoyé du serveur au client les infos de base du serveur
      * @author Sam101
      */
    class HelloMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de HelloMessage
              */
            static const qint32 MAGICNUMBER_HELLOMESSAGE = 0x4200;
        protected:
            /**
              * Nom du serveur
              */
            QString _name;
            /**
              * Version du protocole
              */
            qint32 _version;
        public:
            /**
              * Constructeur
              */
            HelloMessage(QString name, qint32 version);
            /**
              * Renvoie le nom du serveur
              */
            QString getName() const;
            /**
              * Renvoie la version du protocole
              */
            qint32 getVersion() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const HelloMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, HelloMessage &m);
    };
}
#endif //NETWORK_HELLOMESSAGE_H
