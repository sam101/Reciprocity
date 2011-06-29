#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H
#include <QtNetwork/QTcpSocket>
namespace Server
{
    /**
      * Gère les informations liées à un client
      * @brief Gère les informations liées à un client
      * @author Sam101
      */
    class Client
    {
        protected:
            /**
              * Socket du client
              */
            QTcpSocket *_socket;
            /**
              * Login du client
              * (vide si non renseigné)
              */
            QString _login;
            /**
              * Hash du client
              * (vide si non renseigné)
              */
            QString _hash;
        public:
            /**
              * Constructeur
              */
            Client(QTcpSocket *socket);
            /**
              * Renvoie le socket du client
              */
            QTcpSocket* getSocket();
            /**
              * Renvoie le socket du client.
              * Surchargé constant
              */
            const QTcpSocket* getSocket() const;
            /**
              * Renvoie le login du client
              */
            QString getLogin() const;
            /**
              * Renvoie le hash du client
              */
            QString getHash() const;
            /**
              * Change le login du client
              */
            void setLogin(QString login);
            /**
              * Change le hash du client
              */
            void setHash(QString hash);
    };
}
#endif //SERVER_CLIENT_H
