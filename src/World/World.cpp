#include <World/World.h>
namespace World
{
    /**
      * Constructeur
      */
    World::World() :
    _generator(NULL)
    {
        //On donne la taille de départ du tableau
        _chunkTL.resize(1);
        _chunkTR.resize(1);
        _chunkBL.resize(1);
        _chunkBR.resize(1);
        //On alloue le générateur
        _generator = new WorldGenerator(this);

    }
    /**
      * Destructeur.
      * Détruit toutes les entitées présentes
      * dans le monde
      */
    World::~World()
    {
        if (_generator != NULL)
        {
            delete _generator;
        }
    }
    /**
      * Renvoie un chunk du monde. Les coordonnées
      * sont par chunk (et non par tile).
      * Cette méthode n'est pas const car il y'a possibilité
      * de génération d'un nouveau chunk à l'appel.
      */
    Chunk::Chunk* World::getChunk(int x, int y)
    {
        //On gère les cas positifs/négatifs.
        if (x < 0)
        {
            if (y < 0)
            {
                //On geneère les chunk qui n'existent pas.
                if (abs(x) >= _chunkTL[0].size() || abs(y) >= _chunkTL.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTL[x][y];
            }
            else
            {
                if (abs(x) >= _chunkBL[0].size() || abs(y) >= _chunkBL.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkBL[x][y];
            }
        }
        else
        {
            if (y < 0)
            {
                //On genère les chunk si il y'a besoin
                if (x >= _chunkTR[0].size() || abs(y) >= _chunkTR.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkTR[x][y];
            }
            else
            {
                if (x >= _chunkBR[0].size() || y >= _chunkBR.size())
                {
                    _generator->generate(x,y);
                }
                return _chunkBR[x][y];
            }
        }
    }
}
