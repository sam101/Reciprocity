#ifndef CLIENT_CONNECTIONHANDLER_H
#define CLIENT_CONNECTIONHANDLER_H
#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
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
        protected:
            /**
              * Pointeur vers le socket actuel
              */
            QTcpSocket *_socket;
        public:
            /**
              * Constructeur
              */
            ConnectionHandler();
        public slots:
            /**
              * Méthode lançant une tentative de connexion à un serveur
              * et une tentative d'authentification
              */
            void startConnection(QString address, qint32 port, QString login, QString path);
            /**
              * Gère les erreurs.
              */
            void handleError(QAbstractSocket::SocketError);
        signals:
            /**
              * Envoyé quand le port est incorrect
              */
            void badPort();
            /**
              * Envoyé quand le nom de domaine n'a pu être résolu
              */
            void hostnameNotFound();
            /**
              * Envoyé quand il y'a une erreur inconnue.
              */
            void unknownError();
    };
}
#endif //CLIENT_CONNECTIONHANDLER_H
