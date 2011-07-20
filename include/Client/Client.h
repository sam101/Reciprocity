#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>
namespace Client
{
    /**
      * Gère la connexion et l'envoi de messages avec un serveur
      * @brief Gère la connexion avec un serveur
      * @author Sam101
      */
    class Client : public QObject
    {
        Q_OBJECT
        protected:
            /**
               * Pointeur vers le socket du client
               */
            QTcpSocket *_socket;
            /**
              * Indique si on est actuellement authentifié
              */
            bool _isLogged;
            /**
              * Login du joueur
              */
            QString _login;
            /**
              * Hash du joueur
              */
            QString _hash;
        public:
            /**
              * Constructeur
              */
            Client(QTcpSocket *socket, QString login, QString hash);
            /**
              * Renvoie le login du client
              */
            QString getLogin() const;
            /**
              * Renvoie le hash du client
              */
            QString getHash() const;
        public slots:
            /**
              * Envoie un message de login
              */
            void sendLoginMessage();
            /**
              * Appelé quand le client reçoit un message du socket
              */
            void messageRecevied();
    };
}
#endif //CLIENT_CLIENT_H
