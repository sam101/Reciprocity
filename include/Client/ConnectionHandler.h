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
        public slots:
            /**
              * Méthode lançant une tentative de connexion à un serveur
              * et une tentative d'authentification
              */
            void startConnection(QString address, qint32 port, QString login, QString path);
        signals:
            /**
              * Envoyé quand le nom de domaine n'a pu être résolu
              */
            void hostnameNotFound();
    };
}
#endif //CLIENT_CONNECTIONHANDLER_H
