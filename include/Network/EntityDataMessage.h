#ifndef NETWORK_ENTITYDATAMESSAGE_H
#define NETWORK_ENTITYDATAMESSAGE_H
#include <Network/AbstractMessage.h>
#include <Map/Entity.h>
namespace Network
{
    /**
      * Message envoyé du serveur au client, contient des informations
      * sur une entité
      * @brief Contient des informations sur une entité
      * @author Sam101
      */
    class EntityDataMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de EntityDataMessage
              */
            static const qint32 MAGICNUMBER_ENTITYDATA = 0x4214;
        protected:
            /**
              * Données de l'entité
              */
            Map::Entity _entity;
        public:
            /**
              * Constructeur sans paramètres
              */
            EntityDataMessage();
            /**
              * Constructeur
              */
            EntityDataMessage(const Map::Entity &entity);
            /**
              * Renvoie l'entité
              */
            Map::Entity& getEntity();
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const EntityDataMessage &m);
            /**
              * Recupère le message d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, EntityDataMessage &m);
    };
}
#endif //NETWORK_ENTITYDATAMESSAGE_H
