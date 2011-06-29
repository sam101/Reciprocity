#ifndef NETWORK_MESSAGETYPE_H
#define NETWORK_MESSAGETYPE_H
namespace Network
{
    /**
      * Gère les types de message pouvant être envoyés
      * @brief Gère les types de message pouvant être envoyés
      * @author Sam101
      */
    enum MessageType
    {
        ERROR = -1,
        NONE = 0,
        LOGIN = 1,
        LOGIN_FAILED = 2,
        LOGIN_SUCCESS = 3,
        KICK = 4,
        CHUNKDATA = 5,
        ENTITYDATA = 6,
        MOVEUNIT = 7,
        MOVEUNIT_ACCEPTED = 8,
        MOVEUNIT_FAILED = 9
    };
}
#endif //NETWORK_MESSAGETYPE_H
