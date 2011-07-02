#include <Network/LoginMessage.h>
namespace Network
{
    /**
      * Constructeur sans paramètres
      */
    LoginMessage::LoginMessage() :
    AbstractMessage(LOGIN),
    _version(0)
    {

    }
    /**
      * Constructeur
      */
    LoginMessage::LoginMessage(qint32 version,QString login, QString hash) :
    AbstractMessage(LOGIN),
    _version(version),
    _login(login),
    _hash(hash)
    {

    }
    /**
      * Renvoie le login à utiliser
      */
    QString LoginMessage::getLogin() const
    {
        return _login;
    }
    /**
      * Renvoie le hash à utiliser
      */
    QString LoginMessage::getHash() const
    {
        return _hash;
    }
    /**
      * Envoie le LoginMessage dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const LoginMessage &l)
    {
        //On stocke le magicnumber
        out << l.MAGICNUMBER_LOGINMESSAGE;
        //On stocke les informations;
        out << l._version;
        out << l._login;
        out << l._hash;

        return out;
    }
    /**
      * Recupère un LoginMessage d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, LoginMessage &l)
    {
        //On vérifie le magicnumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != l.MAGICNUMBER_LOGINMESSAGE) return in;
        //On recupère les données
        in >> l._version;
        in >> l._login;
        in >> l._hash;

        return in;
    }
}
