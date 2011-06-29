#ifndef SERVER_MESSAGEHANDLER_H
#define SERVER_MESSAGEHANDLER_H
#include <QtNetwork/QTcpSocket>
#include <QtCore/QObject>
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
              * Stocke les tailles de message
              */
            QMap<QTcpSocket*,quint16> _sizes;
        public:
            /**
              * Constructeur
              */
            MessageHandler(Game::Game *game);
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
