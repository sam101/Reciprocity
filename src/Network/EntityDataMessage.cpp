#include <Network/EntityDataMessage.h>
namespace Network
{
    /**
     * Constructeur sans paramètres
     */
    EntityDataMessage::EntityDataMessage() :
    AbstractMessage(Network::ENTITYDATA)
    {

    }
    /**
      * Constructeur
      */
    EntityDataMessage::EntityDataMessage(const Map::Entity &entity) :
    AbstractMessage(Network::ENTITYDATA),
    _entity(entity)
    {

    }
    /**
      * Renvoie l'entité
      */
    Map::Entity& EntityDataMessage::getEntity()
    {
        return _entity;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const EntityDataMessage &m)
    {
        //On écrit le magicNumber
        out << m.MAGICNUMBER_ENTITYDATA;
        //On écrit les données
        out << m._entity;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, EntityDataMessage &m)
    {
        //On vérifie le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_ENTITYDATA)
        {
            return in;
        }
        //On recupère les données
        in >> m._entity;

        return in;
    }

}
