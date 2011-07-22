#include <Network/MessageOutMessage.h>
namespace Network
{
    /**
      * Constructeur sans paramètres.
      */
    MessageOutMessage::MessageOutMessage() :
    AbstractMessage(Network::MESSAGE_OUT)
    {

    }
    /**
      * Constructeur
      */
    MessageOutMessage::MessageOutMessage(QString contents, QString dest) :
    AbstractMessage(Network::MESSAGE_OUT),
    _contents(contents),
    _dest(dest)
    {
    }
    /**
      * Renvoie le contenu du message
      */
    QString MessageOutMessage::getContents() const
    {
        return _contents;
    }
    /**
      * Renvoie le destinataire du message
      */
    QString MessageOutMessage::getDest() const
    {
        return _dest;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const MessageOutMessage &m)
    {
        //On stocke le MagicNumber
        out << m.MAGICNUMBER_MESSAGEOUTMESSAGE;
        //On stocke les informations
        out << m._contents;
        out << m._dest;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, MessageOutMessage &m)
    {
        //On recupère le MagicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_MESSAGEOUTMESSAGE) return in;
        //On recupère les données
        in >> m._contents;
        in >> m._dest;

        return in;
    }
}
