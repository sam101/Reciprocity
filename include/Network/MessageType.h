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
        IP_BANNED = -3,
        SERVER_IS_FULL = -2,
        ERROR = -1,
        NONE = 0,
        LOGIN = 1,
        LOGIN_FAILED = 2,
        LOGIN_SUCCESS = 3,
        KICK_PLAYER = 4,
        KICK = 5,
        GET_SERVER_DATA = 6,
        SERVER_DATA = 7,
        MESSAGE_OUT = 8,
        MESSAGE_IN = 9,
        REQUEST_DATA = 10,
        CHUNKDATA = 11,
        ENTITYDATA = 12,
        MOVEUNIT = 13,
        MOVEUNIT_ACCEPTED = 14,
        BUILD = 15,
        BUILD_ACCEPTED = 16,
        WORK = 17,
        ENDTURN = 18,
        NEWTURN = 19
    };
}
#endif //NETWORK_MESSAGETYPE_H
