#include <Network/LoginSuccessMessage.h>
namespace Network
{
    /**
      * Constructeur
      */
    LoginSuccessMessage::LoginSuccessMessage(qint32 id) :
    AbstractMessage(LOGIN_SUCCESS),
    _id(id)
    {

    }
    /**
      * Renvoie l'id
      */
    qint32 LoginSuccessMessage::getId() const
    {
        return _id;
    }
}
