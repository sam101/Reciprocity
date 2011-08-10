#ifndef NETWORK_BUILDMESSAGE_H
#define NETWORK_BUILDMESSAGE_H
#include <Network/AbstractMessage.h>
#include <Map/BuildingType.h>
namespace Network
{
    /**
      * Envoyé du client au serveur, demande de construction d'un
      * batiment
      * @brief Demande de construction d'un batiment
      * @author Sam101
      */
    class BuildMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de BuildMessage
              */
            static const qint32 MAGICNUMBER_BUILD = 0x4217;
        protected:
            /**
              * Entité qui doit construire
              */
            qint32 _entity;
            /**
              * Batiment à construire
              */
            Map::BuildingType _type;
      public:
            /**
              * Constructeur
              */
            BuildMessage(qint32 entity = -1, Map::BuildingType type = Map::NONE);
            /**
              * Renvoie l'entité qui doit construire
              */
            qint32 getEntity() const;
            /**
              * Renvoie le batiment à construire
              */
            Map::BuildingType getType() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const BuildMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, BuildMessage &m);
    };
}
#endif //NETWORK_BUILDMESSAGE_H
