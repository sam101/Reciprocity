#ifndef NETWORK_MOVEUNITMESSAGE_H
#define NETWORK_MOVEUNITMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Envoyé du client au serveur.
      * Demande de déplacement d'une unité
      * @brief Demande de déplacement d'une unité
      * @author Sam101
      */
    class MoveUnitMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de MoveUnitMessage
              */
            static const qint32 MAGICNUMBER_MOVEUNIT = 0x4215;
        protected:
            /**
              * Id de l'entité à déplacer
              */
            qint32 _id;
            /**
              * Déplacement X de l'entité
              */
            qint32 _x;
            /**
              * Déplacement Y de l'entité
              */
            qint32 _y;
       public:
            /**
              * Constructeur
              */
            MoveUnitMessage(qint32 id = -1, qint32 x = 0, qint32 y = 0);
            /**
              * Renvoie l'id de l'entité à déplacer
              */
            qint32 getId() const;
            /**
              * Renvoie le déplacement X de l'entité
              */
            qint32 getX() const;
            /**
              * Renvoie le déplacement Y de l'entité
              */
            qint32 getY() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const MoveUnitMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, MoveUnitMessage &m);

    };
}
#endif //NETWORK_MOVEUNITMESSAGE_H
