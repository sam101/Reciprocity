#ifndef NETWORK_RESOURCEMESSAGE_H
#define NETWORK_RESOURCEMESSAGE_H
#include <Network/AbstractMessage.h>
namespace Network
{
    /**
      * Gère un déplacement de ressources depuis
      * une entité vers une tile, ou d'une tile vers une entité,
      * ou d'une entité vers une entité adjacente
      * @brief Gère un déplacement de ressources
      * @author Sam101
      */
    class ResourceMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de ResourceMessage
              */
            static const qint32 MAGICNUMBER_RESOURCE = 0x4221;
            /**
              * Types de déplacement possibles
              */
            enum MoveType
            {
                NONE = -1,
                ENTITY_TILE = 0,
                TILE_ENTITY = 1,
                ENTITY_ENTITY = 2
            };

        protected:
            /**
              * Type de déplacement
              */
            MoveType _type;
            /**
              * Id de l'entité source
              */
            qint32 _entityId;
            /**
              * Id de l'entité destination (si besoin)
              */
            qint32 _entityIdDest;
        public:
            /**
              * Constructeur
              */
            ResourceMessage(MoveType type = NONE, qint32 entityId = -1, qint32 entityIdDest = -1);
    };
}
#endif //NETWORK_RESOURCEMESSAGE_H
