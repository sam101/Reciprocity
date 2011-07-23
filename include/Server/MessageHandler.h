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
            QMap<QTcpSocket*, Client*> &_clients;
            /**
              * Stocke les tailles de message
              */
            QMap<QTcpSocket*,qint32> _sizes;
        public:
            /**
              * Constructeur
              */
            MessageHandler(QMap<QTcpSocket*,Client*> &clients);
            /**
              * Définit l'objet de jeu actuel
              */
            void setGame(Game::Game *game);
        public slots:
            /**
              * Appelé lors de la reception d'un message.
              * Detecte le type du message envoyé et
              * appelle la méthode correspondante au message reçu.
              */
            void messageRecevied();
            /**
              * Gère le login d'un joueur
              */
            void handleLogin(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'un message par un joueur
              */
            void handleMessage(QTcpSocket *socket, QDataStream &in);
        signals:
            /**
              * Emis quand le login demmandé par le joueur existe déjà
              */
            void loginAlreadyExists(QTcpSocket*, QString);
            /**
              * Emis quand le login à réussi.
              */
            void loginSuccess(QTcpSocket*,qint32,bool);
            /**
              * Emis quand le client a émit un message incorrect
              */
            void errorMessage(QTcpSocket*);
            /**
              * Emit quand un message doit être envoyé
              */
            void sendMessage(QString dest, QString contents);
    };
}
#endif //SERVER_MESSAGEHANDLER_H
