#include <Network/ErrorMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    ErrorMessage::ErrorMessage(QString message) :
    AbstractMessage(Network::ERROR),
    _message(message)
    {

    }
    /**
      * Renvoie l'intitulé du message d'erreur
      */
    QString ErrorMessage::getMessage() const
    {
        return _message;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const ErrorMessage &e)
    {
        //On envoie le MagicNumber
        out << e.MAGICNUMBER_ERRORMESSAGE;
        //on envoie les données
        out << e._message;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, ErrorMessage &e)
    {
        //On recupère le MagicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != e.MAGICNUMBER_ERRORMESSAGE) return in;
        //On recupère les données
        in >> e._message;

        return in;
    }
}
