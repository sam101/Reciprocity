#ifndef NETWORK_MOVEUNITACCEPTED_H
#define NETWORK_MOVEUNITACCEPTED_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Message envoyé du serveur au client signalant que le déplacement
      * d'une entité à réussi
      * @brief Signale qu'un déplacement à réussi
      * @author Sam101
      */
    class MoveUnitAcceptedMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de MoveUnitAcceptedMessage
              */
            static const qint32 MAGICNUMBER_MOVEUNIT_ACCEPTED = 0x4216;
        protected:
            /**
              * Id de l'entité qui a été déplacée
              */
            qint32 _id;
            /**
              * Nouvelle position X de l'entité
              */
            qint32 _x;
            /**
              * Nouvelle position Y de l'entité
              */
            qint32 _y;
        public:
            /**
              * Constructeur
              */
            MoveUnitAcceptedMessage(qint32 id = -1, qint32 x = 0, qint32 y = 0);
            /**
              * Renvoie l'id de l'entité déplacée
              */
            qint32 getId() const;
            /**
              * Renvoie la position X de l'entité
              */
            qint32 getX() const;
            /**
              * Renvoie la position Y de l'entité
              */
            qint32 getY() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const MoveUnitAcceptedMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, MoveUnitAcceptedMessage &m);
    };
}
#endif //NETWORK_MOVEUNITACCEPTED_H
