#include <World/World.h>
namespace World
{
    /**
      * Constructeur
      */
    World::World()
    {

    }
    /**
      * Destructeur.
      * Détruit toutes les entitées présentes
      * dans le monde
      */
    World::~World()
    {

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

            }
            else
            {

            }
        }
        else
        {

        }
    }
}
