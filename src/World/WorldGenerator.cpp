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
      * Redimensionne la taille des tableaux de chunk
      */
    void WorldGenerator::_redim(qint32 x, qint32 y)
    {
        if (y < 0)
        {
            if (x < 0)
            {
                if (y >= _world->_chunkBL.size())
                {
                    _world->_chunkBL.resize(y);
                }

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
    /**
      * Demande la génération d'un chunk.
      * Peut entrainer en cascade la génération d'autres
      * chunk.
      * @param x Position X du chunk à générer.
      * @param y Position Y du chunk à générer.
      */
    void WorldGenerator::generate(qint32 x, qint32 y)
    {
        _redim(x,y);
    }
}
