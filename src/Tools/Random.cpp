#include <Tools/Random.h>
#include <cstdlib>
namespace Tools
{
    /**
     * Graine utilisée pour la génération des nombres aléatoires
     */
    int Random::_seed = 0;
    /**
     * Nombre de nombres aléatoires déjà générés
     */
    int Random::_state = 0;
    /**
     * Initialise le générateur de nombres pseudo-aléatoires
     * @param seed Graine à utiliser
     * @param Etat actuel du générateur
     */
    void Random::init(int seed, int state)
    {
        _seed = seed;
        _state = state;

        for (int i = 0; i < _state; i++)
        {
            rand();
        }
    }
    /**
     * Renvoie un nombre pseudo-aléatoire entre min et max
     * @param seed Minimum du nombre
     * @param max Maximum du nombre
     */
     int Random::next(int min, int max)
     {
         return (rand() % (max - min)) + min;
     }
    /**
     * Renvoie la seed actuelle
     */
    int Random::getSeed()
    {
        return _seed;
    }
    /**
      * Renvoie le nombre de nombres aléatoires déjà générés
      */
    int Random::getState()
    {
        return _state;
    }
}
