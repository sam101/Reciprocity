#ifndef SERVER_MESSAGEHANDLER_H
#define SERVER_MESSAGEHANDLER_H
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>

#include <Server/Client.h>
#include <Game/Game.h>
#include <QtCore/QMap>
namespace Server
{
    /**
      * Gère les messages envoyés par les clients au serveur.
      * @brief Gère les messages envoyés par les clients au serveur.
      * @author Sam101
      */
    class MessageHandler : public QObject
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers l'objet de jeu
              */
            Game::Game *_game;
            /**
              * Map des clients
              */
            QMap<QTcpSocket*, Client*> _clients;
            /**
              * Stocke les tailles de message
              */
            QMap<QTcpSocket*,qint32> _sizes;
        public:
            /**
              * Constructeur
              */
            MessageHandler(QMap<QTcpSocket*,Client*> clients);
        public slots:
            /**
              * Appelé lors de la reception d'un message.
              * Detecte le type du message envoyé et
              * appelle la méthode correspondante au message reçu.
              */
            void messageRecevied();
    };
}
#endif //SERVER_MESSAGEHANDLER_H
