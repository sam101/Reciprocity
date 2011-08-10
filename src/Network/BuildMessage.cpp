#include <Network/BuildMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    BuildMessage::BuildMessage(qint32 entity, Map::BuildingType type) :
    AbstractMessage(Network::BUILD),
    _entity(entity),
    _type(type)
    {

    }
    /**
      * Renvoie l'entité qui doit construire
      */
    qint32 BuildMessage::getEntity() const
    {
        return _entity;
    }
    /**
      * Renvoie le batiment à construire
      */
    Map::BuildingType BuildMessage::getType() const
    {
        return _type;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const BuildMessage &m)
    {
        //On écrit le magicNumber
        out << m.MAGICNUMBER_BUILD;
        //On écrit les données
        out << m._entity;
        out << (qint32)m._type;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, BuildMessage &m)
    {
        //On vérifie le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_BUILD)
        {
            return in;
        }
        //On recupère les données
        in >> m._entity;
        in >> (qint32&)m._type;

        return in;
    }
}
