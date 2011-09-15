#include <Network/WorkMessage.h>
namespace Network
{
    /**
      * Constructeur sans paramètres
      */
    WorkMessage::WorkMessage(qint32 entity) :
    AbstractMessage(Network::WORK),
    _entity(entity)
    {

    }
    /**
      * Renvoie l'entité qui doit travailler
      */
    qint32 WorkMessage::getEntity() const
    {
        return _entity;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const WorkMessage &m)
    {
        out << (qint32)m.MAGICNUMBER_WORK;
        out << m._entity;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, WorkMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;

        in >> m._entity;

        return in;
    }
}
