#ifndef TOOLS_CLIENTSETTINGS_H
#define TOOLS_CLIENTSETTINGS_H
#include <QtCore/QSettings>
namespace Tools
{
    /**
      * Stocke les préférences de jeu dans le client
      * @brief Stocke les préférences de jeu dans le client
      * @author Sam101
      */
    class ClientSettings
    {
        protected:
            /**
              * Objet des paramètres
              */
            static QSettings *_settings;
            /**
              * Constructeur
              */
            ClientSettings()
            {

            }

        public:
            /**
              * Initialise l'objet de préférences
              */
            void init();
            /**
              * Renvoie une valeur de la configuration
              */
            static QVariant getValue(QString key, QVariant defaultValue);
            /**
              * Ecrit une valeur dans la configuration
              */
            static void setValue(QString key, QVariant value);
    };
}
#endif //TOOLS_CLIENTSETTINGS_H
