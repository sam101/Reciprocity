#include <Network/MoveUnitAcceptedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    MoveUnitAcceptedMessage::MoveUnitAcceptedMessage(qint32 id, qint32 x, qint32 y) :
    AbstractMessage(Network::MOVEUNIT_ACCEPTED),
    _id(id),
    _x(x),
    _y(y)
    {

    }
    /**
      * Renvoie l'id de l'entité déplacée
      */
    qint32 MoveUnitAcceptedMessage::getId() const
    {
        return _id;
    }
    /**
      * Renvoie la position X de l'entité
      */
    qint32 MoveUnitAcceptedMessage::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position Y de l'entité
      */
    qint32 MoveUnitAcceptedMessage::getY() const
    {
        return _y;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const MoveUnitAcceptedMessage &m)
    {
        //On envoie le magicNumber
        out << m.MAGICNUMBER_MOVEUNIT_ACCEPTED;
        //On envoie les données
        out << m._id;
        out << m._x;
        out << m._y;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, MoveUnitAcceptedMessage &m)
    {
        //On vérifie le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_MOVEUNIT_ACCEPTED)
        {
            return in;
        }
        //On recupère les données
        in >> m._id;
        in >> m._x;
        in >> m._y;

        return in;
    }
}
