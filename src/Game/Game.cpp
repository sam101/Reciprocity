#include <Game/Game.h>
namespace Game
{
    /**
      * Constructeur
      */
    Game::Game() :
    _world(NULL)
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
}
