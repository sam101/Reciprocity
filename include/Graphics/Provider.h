#ifndef GRAPHICS_PROVIDER_H
#define GRAPHICS_PROVIDER_H
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtGui/QPixmap>
namespace Graphics
{
    /**
      * Charge différantes données graphiques de jeu
      * @brief Charge différantes données graphiques de jeu
      * @author Sam101
      */
    class Provider
    {
        protected:
            /**
              * Chemin vers les données de jeu
              */
            static QString _path;
            /**
              * Cache des tiles utilisées dans  le jeu
              */
            QMap<QString,QPixmap> _tiles;
        public:
            static void init(QString path);
    };
}
#endif //GRAPHICS_PROVIDER_H