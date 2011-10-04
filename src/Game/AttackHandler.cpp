#include <Game/AttackHandler.h>
namespace Game
{
    /**
      * Constructeur
      */
    AttackHandler::AttackHandler(World::World *world, QList<Player *> &players) :
    _world(world),
    _players(players)
    {

    }
    /**
      * Fait attaquer une entité
      */
    bool AttackHandler::attack(qint32 entityId, qint32 x, qint32 y)
    {
        return false;
    }
}
