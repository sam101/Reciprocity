#ifndef NETWORK_ATTACKHANDLER_H
#define NETWORK_ATTACKHANDLER_H
namespace Network
{
    /**
      * Gère la gestion de l'attaque d'une entité sur une entité/batiment
      * @brief Gère la gestion de l'attaque d'une entité sur une entité/batiment
      * @author Sam101
      */
    class AttackHandler
    {
        protected:
            /**
              * Pointeur vers l'objet monde
              */
            World::World *_world;
            /**
              * Tableau des joueurs
              */
            QList<Player*> &_players;
        public:

    };
}
#endif //NETWORK_ATTACKHANDLER_H
