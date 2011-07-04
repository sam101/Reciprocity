#include <Network/LoginFailedMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    LoginFailedMessage::LoginFailedMessage(qint32 why) :
    AbstractMessage(LOGIN_FAILED),
    _why(why)
    {

    }
    /**
      * Renvoie la raison pour laquelle le login a echoué
      */
    qint32 LoginFailedMessage::getWhy() const
    {
        return _why;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const LoginFailedMessage &l)
    {
        out << l.MAGICNUMBER_LOGINFAILEDMESSAGE;
        out << l._why;
        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, LoginFailedMessage &l)
    {
        //On teste le magicNumber.
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != l.MAGICNUMBER_LOGINFAILEDMESSAGE) return in;
        //On recupère les données
        in >> l._why;

        return in;
    }
}
