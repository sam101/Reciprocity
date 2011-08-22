#ifndef MAP_BUILDINGTYPE_H
#define MAP_BUILDINGTYPE_H
namespace Map
{
    /**
      * Stocke les divers types de batiment
      * @brief Stocke les divers types de batiment
      * @author Sam101
      */
    enum BuildingType
    {
        /**
          * Aucun batiment
          */
        NONE = 0,
        /**
          * Maison, loge les entitées
          */
        HOUSE = 1,
        /**
          * Ferme, sert à cultiver pour récupérer de la nouriture
          */
        FARMLAND = 2
    };
}
#endif //MAP_BUILDINGTYPE_H
