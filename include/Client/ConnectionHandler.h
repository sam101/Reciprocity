#ifndef CLIENT_CONNECTIONHANDLER_H
#define CLIENT_CONNECTIONHANDLER_H
#include <QtCore/QObject>
namespace Client
{
    /**
      * Gère la connexion avec un serveur, connecte le socket avant d'envoyer le message de login
      * @brief Gère la connexion avec un serveur
      * @author Sam101
      */
    class ConnectionHandler : public QObject
    {
        Q_OBJECT
    };
}
#endif //CLIENT_CONNECTIONHANDLER_H
