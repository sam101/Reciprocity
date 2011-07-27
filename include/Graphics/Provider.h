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
            static QMap<QString,QPixmap> _tiles;
            /**
              * Cache des batiments utilisés dans le jeu
              */
            static QMap<QString,QPixmap> _buildings;
    public:
            /**
              * Initialise le chemin vers lequel on doit trouver les données
              */
            static void init(QString path);
            /**
              * Renvoie un Pixmap d'une tile
              */
            static QPixmap getTile(QString name);
            /**
              * Renvoie un Pixmap d'un batiment
              */
            static QPixmap getBuilding(QString name);
    };
}
#endif //GRAPHICS_PROVIDER_H
