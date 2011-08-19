#include <Network/NewTurnMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    NewTurnMessage::NewTurnMessage(qint32 turn) :
    AbstractMessage(Network::NEWTURN),
    _turn(turn)
    {

    }

    /**
      * Renvoie le numéro du tour
      */
    qint32 NewTurnMessage::getTurn() const
    {
        return _turn;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const NewTurnMessage &m)
    {
        out << m.MAGICNUMBER_NEWTURN;
        out << m._turn;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, NewTurnMessage &m)
    {
        //On recupère le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_NEWTURN)
        {
            return in;
        }
        //On recupère les données
        in >> m._turn;

        return in;
    }
}
