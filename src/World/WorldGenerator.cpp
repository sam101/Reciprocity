#include <World/WorldGenerator.h>
#include <World/World.h>
#include <Config/Config.h>
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
      * Redimensionne la taille des tableaux de chunk.
      * Positionne aussi la position des chunk nouvellement conçus.
      */
    void WorldGenerator::_redim(qint32 x, qint32 y)
    {
        int oldSize;
        if (y < 0)
        {
            if (x < 0)
            {
                if (abs(y) >= _world->_chunkTL.size())
                {
                    _world->_chunkTL.resize(abs(y) + 1);
                }
                for (int i = 1; i <= abs(y); i++)
                {
                    oldSize = _world->_chunkTL.size();
                    _world->_chunkTL[i].resize(abs(x) + 1);
                }
            }
            else
            {
                if (abs(y) >= _world->_chunkTR.size())
                {
                    _world->_chunkTR.resize(abs(y) + 1);
                }
                for (int i = 1; i <= abs(y); i++)
                {
                    oldSize = _world->_chunkTR.size();
                    _world->_chunkTR[i].resize(x + 1);
                }

            }
        }
        else
        {
            if (x < 0)
            {
                if (y >= _world->_chunkBL.size())
                {
                    _world->_chunkBL.resize(y + 1);
                }
                for (int i = 1; i <= y; i++)
                {
                    oldSize = _world->_chunkBL.size();
                    _world->_chunkBL[i].resize(abs(x) + 1);
                    for (int j = oldSize; j < (abs(x) + 1); j++)
                    {
                        _world->_chunkBL[i][j] = new Chunk::Chunk(-1 * j * Config::Config::CHUNK_SIZE - 1, i * Config::Config::CHUNK_SIZE);
                    }
                }
            }
            else
            {
                if (y >= _world->_chunkBR.size())
                {
                    _world->_chunkBR.resize(y + 1);
                }
                for (int i = 1; i <= y; i++)
                {
                    oldSize = _world->_chunkBR.size();
                    _world->_chunkBR[i].resize(x + 1);
                    for (int j = oldSize; j < (abs(x) + 1); j++)
                    {
                        _world->_chunkBR[i][j] = new Chunk::Chunk(j * Config::Config::CHUNK_SIZE, i * Config::Config::CHUNK_SIZE);
                    }
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
