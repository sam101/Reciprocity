#ifndef NETWORK_DELETEMESSAGE_H
#define NETWORK_DELETEMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Gère la suppression d'une entité/d'un batiment
      * @brief Gère la suppression d'une entité/d'un batiment
      * @author Sam101
      */
    class DeleteMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de DeleteMessage
              */
            static const qint32 MAGICNUMBER_DELETE = 0x4227;
            /**
              * Type de suppression possibles
              */
            enum DeleteType
            {
                NONE = 0,
                ENTITY = 1,
                BUILDING = 2
            };
        protected:
            /**
              * Type de la suppression
              */
            DeleteType _type;
            /**
              * Position X à détruire
              */
            qint32 _x;
            /**
              * Position Y à détruire
              */
            qint32 _y;

            /**
              * Id de l'entité à détruire
              */
            qint32 _entityId;
        public:
            /**
              * Constructeur
              */
            DeleteMessage(DeleteType type = NONE, qint32 x = 0, qint32 y = 0, qint32 entityId = -1);
            /**
              * Renvoie la position X
              */
            qint32 getX() const;
            /**
              * Renvoie la position Y
              */
            qint32 getY() const;
            /**
              * Renvoie l'id de l'entité à détruire
              */
            qint32 getEntityId() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const DeleteMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, DeleteMessage &m);
    };
}
#endif //NETWORK_DELETEMESSAGE_H
