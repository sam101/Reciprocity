#ifndef CLIENT_CONNECTIONHANDLER_H
#define CLIENT_CONNECTIONHANDLER_H
#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <Client/Client.h>
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
            /**
              * Pointeur vers l'objet Client.
              */
            Client *_client;
            /**
              * Login à utiliser
              */
            QString _login;
            /**
              * Hash à utiliser
              */
            QString _hash;
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
            void startConnection(QString address, qint32 port, QString login, QString hash);
            /**
              * Gère les erreurs.
              */
            void handleError(QAbstractSocket::SocketError);
            /**
              * Appelé quand le chemin à pu être resolu.
              */
            void hostFoundHandler();
            /**
              * Appelé quand la connexion a été établie
              */
            void connectedHandler();
            /**
              * Appelé quand le login a réussi
              */
            void loginSuccessHandler();
            /**
              * Appelé quand le login a échoué
              */
            void loginFailedHandler();
            /**
              * Déconnecte le client actuel
              */
            void logout();
        signals:
            /**
              * Envoyé quand l'objet client a changé
              */
            void clientHasChanged(QObject*);
            /**
              * Envoyé quand le port est incorrect
              */
            void badPort();
            /**
              * Envoyé quand la connexion a été refusée
              */
            void connectionRefused();
            /**
              * Envoyé quand le nom de domaine n'a pu être résolu
              */
            void hostnameNotFound();
            /**
              * Envoyé quand il y'a une erreur inconnue.
              */
            void unknownError();
            /**
              * Envoyé quand le login a échoué
              */
            void loginFailedError();
            /**
              * Envoyé quand le nom d'hote a été trouvé
              */
            void hostFound();
            /**
              * Envoyé quand la connexion est établie
              */
            void connectedToServer();
            /**
              * Envoyé quand le login à réussi.
              */
            void loginSuccess();
    };
}
#endif //CLIENT_CONNECTIONHANDLER_H
