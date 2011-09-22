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
        HELLO = 0,
        LOGIN = 1,
        LOGIN_FAILED = 2,
        LOGIN_SUCCESS = 3,
        KICK_PLAYER = 4,
        KICK = 5,
        GET_SERVER_DATA = 6,
        SERVER_DATA = 7,
        MESSAGE_OUT = 8,
        MESSAGE_IN = 9,
        BEGIN_GAME = 10,
        GAME_HAS_BEGUN = 11,
        REQUEST_DATA = 12,
        CHUNKDATA = 13,
        ENTITYDATA = 14,
        MOVEUNIT = 15,
        MOVEUNIT_ACCEPTED = 16,
        BUILD = 17,
        BUILD_ACCEPTED = 18,
        WORK = 19,
        WORK_ACCEPTED = 20,
        RESOURCE = 21,
        ENDTURN = 22,
        NEWTURN = 23,
        ATTACK = 24,
        ATTACKED = 25,
        NEWENTITY = 26,
        DELETE = 27
    };
}
#endif //NETWORK_MESSAGETYPE_H
