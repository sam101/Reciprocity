#ifndef CONFIG_CONFIG_H
#define CONFIG_CONFIG_H
#include <QtCore/QString>
namespace Config
{
    /**
      * Gère les paramètres de configuration
      * @brief Gère les paramètres de configuration
      * @author Sam101
      */
    class Config
    {
        public:
            //TODO: Faire une classe qui permetterait de charger/modifier les valeurs
            /**
              * Version du protocole
              */
            static const qint32 PROTOCOL_VERSION = 1;
    };
}
#endif //CONFIG_CONFIG_H
