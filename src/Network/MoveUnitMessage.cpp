#include <Network/MoveUnitMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    MoveUnitMessage::MoveUnitMessage(qint32 id, qint32 x, qint32 y) :
    AbstractMessage(Network::MOVEUNIT),
    _id(id),
    _x(x),
    _y(y)
    {

    }
    /**
      * Renvoie l'id de l'entité à déplacer
      */
    qint32 MoveUnitMessage::getId() const
    {
        return _id;
    }
    /**
      * Renvoie le déplacement X de l'entité
      */
    qint32 MoveUnitMessage::getX() const
    {
        return _x;
    }
    /**
      * Renvoie le déplacement Y de l'entité
      */
    qint32 MoveUnitMessage::getY() const
    {
        return _y;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const MoveUnitMessage &m)
    {
        //On écrit le magicNumber
        out << m.MAGICNUMBER_MOVEUNIT;
        //On écrit les données
        out << m._id;
        out << m._x;
        out << m._y;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, MoveUnitMessage &m)
    {
        //On vérifie le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_MOVEUNIT)
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
