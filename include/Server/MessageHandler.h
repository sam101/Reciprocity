#ifndef SERVER_MESSAGEHANDLER_H
#define SERVER_MESSAGEHANDLER_H
#include <Game/Game.h>
namespace Server
{
    /**
      * Gère les messages envoyés par les clients au serveur.
      * @brief Gère les messages envoyés par les clients au serveur.
      * @author Sam101
      */
    class MessageHandler
    {
        protected:
            /**
              * Pointeur vers l'objet de jeu
              */
            Game::Game *_game;
    };
}
#endif //SERVER_MESSAGEHANDLER_H
