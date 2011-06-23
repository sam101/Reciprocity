#include <Graphics/Provider.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
using namespace Config;
namespace Graphics
{
    QString Provider::_path = "";
    QMap<QString,QPixmap> Provider::_tiles;
    /**
      * Initialise le chemin vers lequel on doit trouver les données
      */
    void Provider::init(QString path)
    {
        _path = path;
    }
    /**
      * Renvoie un Pixmap d'une tile
      */
    QPixmap Provider::getTile(QString name)
    {
        /*
         * Si on l'a déjà chargé, on la renvoie
         */
        if (_tiles.contains(name))
        {
            return _tiles.value(name);
        }
        else
        {
            //On charge le pixmap.
            _tiles[name] = QPixmap(_path + "/Tiles/" + name + ".png");
            return _tiles.value(name);
        }
    }
}
