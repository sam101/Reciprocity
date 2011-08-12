#include <Tools/ClientSettings.h>
#include <QtGui/QDesktopServices>
#include <QtCore/QDebug>
namespace Tools
{
    QSettings* ClientSettings::_settings;
    /**
      * Initialise l'objet de préférences
      */
    void ClientSettings::init()
    {
        _settings = new QSettings(QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/.reciprocity/settings.ini",QSettings::IniFormat);
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
        qDebug() << key << value;
        _settings->setValue(key,value);
    }
}
