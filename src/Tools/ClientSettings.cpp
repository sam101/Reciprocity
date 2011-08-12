#include <Tools/ClientSettings.h>
namespace Tools
{
    QSettings* ClientSettings::_settings;
    /**
      * Initialise l'objet de préférences
      */
    void ClientSettings::init()
    {
        _settings = new QSettings("Reciprocity","Reciprocity");
    }
}
