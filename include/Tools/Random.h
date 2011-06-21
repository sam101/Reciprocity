#ifndef TOOLS_RANDOM_H
#define TOOLS_RANDOM_H
namespace Tools
{
    /**
     * Classe gérant la génération de nombres
     * pseudo-aléatoires
     * @brief Classe gérant la génération de nombres aléatoires
     * @author Sam101
     */
    class Random
    {
    private:
        /**
         * Graine utilisée pour la génération des nombres aléatoires
         */
        static int _seed;
        /**
         * Nombre de nombres aléatoires déjà générés
         */
        static int _state;
        /**
         * Constructeur privé pour éviter de construire un objet de type Random
         */
         Random()
         {

         }
    public:
        /**
         * Initialise le générateur de nombres pseudo-aléatoires
         * @param seed Graine à utiliser
         * @param Etat actuel du générateur
         */
        static void init(int seed, int state = 0);
        /**
         * Renvoie un nombre pseudo-aléatoire entre min et max
         * @param seed Minimum du nombre
         * @param max Maximum du nombre
        */
         static int next(int min, int max);
        /**
          * Renvoie la seed actuelle
          */
        static int getSeed();
        /**
          * Renvoie le nombre de nombres aléatoires déjà générés
          */
        static int getState();
    };
}
#endif //TOOLS_RANDOM_H
