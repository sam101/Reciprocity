#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H
#include <Game/Player.h>
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
            /**
              * Indique si le client est toujours connecté
              */
            bool _isOnline;
            /**
              * Pointeur vers le joueur du client
              */
            Game::Player *_player;
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
              * Renvoie le pointeur vers le joueur du client
              */
            Game::Player* getPlayer();
            /**
              * Renvoie le pointeur vers le joueur du client
              * surchargé constant
              */
            const Game::Player* getPlayer() const;
            /**
              * Renvoie si le client est en ligne
              */
            bool isOnline() const;
            /**
              * Change le login du client
              */
            void setLogin(QString login);
            /**
              * Change le hash du client
              */
            void setHash(QString hash);
            /**
              * Indique que le client est offline
              */
            void setOffline();
            /**
              * Change le joueur utilisé par le client
              */
            void setPlayer(Game::Player *player);
    };
}
#endif //SERVER_CLIENT_H
