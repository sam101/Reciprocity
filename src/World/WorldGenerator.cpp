#include <World/WorldGenerator.h>
#include <World/World.h>
namespace World
{
    /**
      * Constructeur
      */
    WorldGenerator::WorldGenerator(World *world) :
    _world(world)
    {

    }
    /**
      * Destructeur
      */
    WorldGenerator::~WorldGenerator()
    {

    }
    /**
      * Demande la génération d'un chunk.
      * Peut entrainer en cascade la génération d'autres
      * chunk.
      * @param x Position X du chunk à générer.
      * @param y Position Y du chunk à générer.
      */
    void WorldGenerator::generate(qint32 x, qint32 y)
    {
        if (y < 0)
        {
            if (y > _world->_chunkBL.size())
            {

            }

            if (x < 0)
            {
            }
            else
            {

            }
        }
        else
        {
            if (x < 0)
            {

            }
            else
            {

            }
        }
    }
}
