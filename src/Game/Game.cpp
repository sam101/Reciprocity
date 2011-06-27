#include <Game/Game.h>
namespace Game
{
    /**
      * Constructeur
      */
    Game::Game() :
    _world(NULL),
    _hasBegun(false)
    {
        //On alloue l'objet de monde
        _world = new World::World;
    }
    /**
      * Destructeur
      */
    Game::~Game()
    {
        if (_world != NULL)
        {
            delete _world;
        }
    }
    /**
      * Renvoie le monde actuel
      */
    World::World* Game::getWorld()
    {
        return _world;
    }
    /**
      * Renvoie le monde actuel
      * Surchargé constant.
      */
    const World::World* Game::getWorld() const
    {
        return _world;
    }
    /**
      * Renvoie si la partie a commencé
      */
    bool Game::hasBegun() const
    {
        return _hasBegun;
    }
}
