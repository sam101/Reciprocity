#include <Graphics/Provider.h>
#include <Config/Config.h>
#include <QtCore/QDebug>
using namespace Config;
namespace Graphics
{
    QString Provider::_path = "";
    QMap<QString,QPixmap> Provider::_tiles;
    QMap<QString,QPixmap> Provider::_buildings;
    QMap<QString,QImage> Provider::_entities;
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
    /**
      * Renvoie un Pixmap d'un batiment
      */
    QPixmap Provider::getBuilding(QString name)
    {
        /*
         * Si on l'a déjà chargé, on la renvoie
         */
        if (_buildings.contains(name))
        {
            return _buildings.value(name);
        }
        else
        {
            //On charge le pixmap.
            _buildings[name] = QPixmap(_path + "/Buildings/" + name + ".png");
            return _buildings.value(name);
        }
    }
    /**
      * Renvoie un QImage d'une entité
      */
    QImage Provider::getEntityI(QString name)
    {
        /*
          * Si on l'a déjà chargé on la renvoie
          */
        if (_entities.contains(name))
        {
            return _entities.value(name);
        }
        else
        {
            //On charge l'image.
            _entities[name] = QImage(_path + "/Buildings/" + name + ".png");
            return _entities.value(name);
        }

    }
}
