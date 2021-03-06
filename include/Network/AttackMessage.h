#ifndef NETWORK_ATTACKMESSAGE_H
#define NETWORK_ATTACKMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message d'attaque d'une entité vers une entité/batiment
      * @brief Message d'attaque d'une entité vers une entité/batiment
      * @author Sam101
      */
    class AttackMessage : public AbstractMessage
    {
        public:
            /**
              * Magic Number de AttackMessage
              */
            static const qint32 MAGICNUMBER_ATTACK = 0x4224;
        protected:
            /**
              * Id de l'entité qui doit attaquer
              */
            qint32 _entityId;
            /**
              * Position X à attaquer
              */
            qint32 _x;
            /**
              * Position Y à attaquer
              */
            qint32 _y;
        public:
            /**
              * Constructeur
              */
            AttackMessage(qint32 entityId = -1, qint32 x = 0, qint32 y = 0);
            /**
              * Renvoie l'id de l'entité
              */
            qint32 getEntityId() const;
            /**
              * Renvoie la position X à attaquer
              */
            qint32 getX() const;
            /**
              * Renvoie la position Y à attaquer
              */
            qint32 getY() const;
            /**
              * Envoie le message un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const AttackMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &i, AttackMessage &m);
    };
}
#endif //NETWORK_ATTACKMESSAGE_H
