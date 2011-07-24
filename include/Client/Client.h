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
              * Indique si on est admin
              */
            bool _isAdmin;
            /**
              * Id du joueur si connecté
              */
            qint32 _id;
            /**
              * Login du joueur
              */
            QString _login;
            /**
              * Hash du joueur
              */
            QString _hash;
            /**
              * Taille du message en cours de reception
              */
            qint32 _messageSize;
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
            /**
              * Renvoie si le joueur est admin
              */
            bool isAdmin() const;
        public slots:
            /**
              * Gère la deconnexion du serveur
              */
            void hasDisconnected();
            /**
              * Envoie un message de login
              */
            void sendLoginMessage();
            /**
              * Envoie le message de demande des informations au serveur
              */
            void sendGetServerData();
            /**
              * Envoie un message de début de partie
              */
            void sendBeginGame();
            /**
              * Envoie un message aux autres joueurs
              */
            void sendChatMessage(QString contents);
            /**
              * Appelé quand le client reçoit un message du socket
              */
            void messageRecevied();
            /**
              * Appelé quand le client doit se déconnecter
              */
            void logout();
        public:

            /**
              * Gère le login du joueur
              */
            void handleLoginSuccess(QDataStream &in);
            /**
              * Gère la reception d'un message
              */
            void handleChatMessage(QDataStream &in);

        signals:
            /**
              * Emit quand le serveur s'est déconnecté
              */
            void serverHasDisconnected();
            /**
              * Emit quand un message incorrect a été reçu
              */
            void incorrectMessage();
            /**
              * Emit quand le login du client à réussi.
              */
            void loginSuccess();
            /**
              * Emit quand le login du client à échoué
              */
            void loginFailed();
            /**
              * Emit quand on a reçu un message de chat
              */
            void messageRecevied(QString sender, QString contents);

    };
}
#endif //CLIENT_CLIENT_H
