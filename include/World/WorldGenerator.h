#ifndef WORLD_WORLDGENERATOR_H
#define WORLD_WORLDGENERATOR_H
namespace World
{
    class World;
    /**
      * Classe s'occupant de la génération du monde
      * c'est à dire la génération du type des chunk présents
      * dans le monde.
      * Il s'occupe également ensuite de la génération du chunk en lui même.
      * @brief S'occupe de la génération du monde
      * @author Sam101
      */
    class WorldGenerator
    {
        protected:
            /**
              * Pointeur vers le monde à générer
              */
            World *_world;
        public:
            /**
              * Constructeur
              */
            WorldGenerator(World *world);
    };
}
#endif //WORLD_WORLDGENERATOR_H
