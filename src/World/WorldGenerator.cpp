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
                y = abs(y);
                x = abs(x);
                if (y >= _world->_chunkTL.size())
                {
                    _world->_chunkTL.resize(y + 1);
                }
                for (int i = 0; i <= y; i++)
                {
                    _world->_chunkTL[i].resize(x + 1);
                }
            }
            else
            {
                y = abs(y);
                if (y >= _world->_chunkTR.size())
                {
                    _world->_chunkTR.resize(y + 1);
                }
                for (int i = 0; i <= y; i++)
                {
                    _world->_chunkTR[i].resize(x + 1);
                }

            }
        }
        else
        {
            if (x < 0)
            {
                x = abs(x);
                if (y >= _world->_chunkBL.size())
                {
                    _world->_chunkBL.resize(y + 1);
                }
                for (int i = 0; i <= y; i++)
                {
                    _world->_chunkBL[i].resize(x + 1);
                }
            }
            else
            {
                if (y >= _world->_chunkBR.size())
                {
                    _world->_chunkBR.resize(y + 1);
                }
                for (int i = 0; i <= y; i++)
                {
                    _world->_chunkBR[i].resize(x + 1);
                }

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
