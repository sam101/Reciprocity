#include <Network/HelloMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    HelloMessage::HelloMessage(QString name, qint32 version) :
    AbstractMessage(Network::HELLO),
    _name(name),
    _version(version)
    {

    }
    /**
      * Renvoie le nom du serveur
      */
    QString HelloMessage::getName() const
    {
        return _name;
    }
    /**
      * Renvoie la version du protocole
      */
    qint32 HelloMessage::getVersion() const
    {
        return _version;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const HelloMessage &m)
    {
        //On envoie le magicNumber
        out << m.MAGICNUMBER_HELLOMESSAGE;
        //On envoie les données
        out << m._name;
        out << m._version;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, HelloMessage &m)
    {
        //On recupère le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        //On recupère les données
        in >> m._name;
        in >> m._version;

        return in;
    }
}
