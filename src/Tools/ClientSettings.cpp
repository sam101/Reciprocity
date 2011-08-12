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
    /**
      * Renvoie une valeur de la configuration
      */
    QVariant ClientSettings::getValue(QString key, QVariant defaultValue)
    {
        return _settings->value(key,defaultValue);
    }
    /**
      * Ecrit une valeur dans la configuration
      */
    void ClientSettings::setValue(QString key, QVariant value)
    {
        _settings->setValue(key,value);
    }
}
