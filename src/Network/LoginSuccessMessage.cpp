#include <Network/LoginSuccessMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    LoginSuccessMessage::LoginSuccessMessage(qint32 id, bool isAdmin) :
    AbstractMessage(LOGIN_SUCCESS),
    _id(id),
    _isAdmin(isAdmin)
    {

    }
    /**
      * Renvoie l'id
      */
    qint32 LoginSuccessMessage::getId() const
    {
        return _id;
    }
    /**
      * Renvoie si le joueur est admin
      */
    bool LoginSuccessMessage::isAdmin() const
    {
        return _isAdmin;
    }
    /**
      * Envoie le message dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const LoginSuccessMessage &l)
    {
        //On stocke le magicnumber
        out << l.MAGICNUMBER_LOGINSUCCESSMESSAGE;
        //On stocke les informations.
        out << l._id;
        out << l._isAdmin;

        return out;
    }
    /**
      * Recupère le message d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, LoginSuccessMessage &l)
    {
        //On vérifie le magicNumber
        qint32 magicNumber;
        in >> magicNumber;
        if (magicNumber != l.MAGICNUMBER_LOGINSUCCESSMESSAGE) return in;
        //On recupère les données
        in >> l._id;
        in >> l._isAdmin;

        return in;
    }
}
