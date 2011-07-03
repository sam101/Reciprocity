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
}
