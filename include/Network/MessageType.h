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
        REQUEST_DATA = 8,
        CHUNKDATA = 9,
        ENTITYDATA = 10,
        MOVEUNIT = 11,
        MOVEUNIT_ACCEPTED = 12,
        BUILD = 13,
        BUILD_ACCEPTED = 14,
        WORK = 15,
        ENDTURN = 16,
        NEWTURN = 17
    };
}
#endif //NETWORK_MESSAGETYPE_H
