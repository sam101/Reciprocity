#ifndef VIEWER_CONFIG_H
#define VIEWER_CONFIG_H
#include <QtCore/Qt>
namespace Viewer
{
    /**
      * Stocke les éléments de configuration de Viewer
      * @brief Stocke les éléments de configuration de Viewer
      * @author Sam101
      */
    class Config
    {
        public:
            /**
              * Stocke la taille d'une tile
              */
            static const qint32 TILE_SIZE = 32;
    };
}
#endif //VIEWER_CONFIG_H
