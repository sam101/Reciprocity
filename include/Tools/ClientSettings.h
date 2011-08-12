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
        public:
            /**
              * Initialise l'objet de préférences
              */
            void init();
    };
}
#endif //TOOLS_CLIENTSETTINGS_H
