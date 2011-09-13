#include <Network/WorkAcceptedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    WorkAcceptedMessage::WorkAcceptedMessage(qint32 entity) :
    AbstractMessage(MAGICNUMBER_WORK_ACCEPTED),
    _entity(entity)
    {

    }
    /**
      * Renvoie l'entité dont le travail a été accepté
      */
    qint32 WorkAcceptedMessage::getEntity() const
    {
        return _entity;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const WorkAcceptedMessage &m)
    {
        out << m.MAGICNUMBER_WORK_ACCEPTED;
        out << m._entity;

        return out;
    }
    /**
      * Recupère le message depuis un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, WorkAcceptedMessage &m)
    {
        qint32 magicNumber;
        in >> magicNumber;

        in >> m._entity;

        return in;
    }
}
