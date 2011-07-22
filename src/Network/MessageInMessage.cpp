#include <Network/MessageInMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    MessageInMessage::MessageInMessage(QString sender, QString contents) :
    AbstractMessage(Network::MESSAGE_IN),
    _sender(sender),
    _contents(contents)
    {

    }
    /**
      * Renvoie l'expéditeur du message
      */
    QString MessageInMessage::getSender() const
    {
        return _sender;
    }
    /**
      * Renvoie le contenu du message
      */
    QString MessageInMessage::getContents() const
    {
        return _contents;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const MessageInMessage &m)
    {
        //On envoie le MagicNumber
        out << m.MAGICNUMBER_MESSAGEINMESSAGE;
        //On envoie les données
        out << m._sender;
        out << m._contents;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, MessageInMessage &m)
    {
        //On vérifie le MagicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != m.MAGICNUMBER_MESSAGEINMESSAGE) return in;
        //On recupère les données
        in >> m._sender;
        in >> m._contents;

        return in;
    }
}
