#include <Network/GameHasBegunMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    GameHasBegunMessage::GameHasBegunMessage() :
    AbstractMessage(Network::GAME_HAS_BEGUN)
    {

    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const GameHasBegunMessage &m)
    {
        out << m.MAGICNUMBER_GAMEHASBEGUN;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, GameHasBegunMessage &m)
    {
        Q_UNUSED(m)
        qint32 magicNumber;
        in >> magicNumber;

        //TODO: Mécanisme de vérification.

        return in;
    }
}
