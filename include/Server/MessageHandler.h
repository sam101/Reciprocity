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
            /**
              * Gère la reception de la demande d'envoi des informations
              */
            void handleGetServerData(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception du message de demmande de début de partie
              */
            void handleBeginGame(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'une demande d'envoi de données
              */
            void handleRequestData(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'une demande de kick de joueur
              */
            void handleKickPlayer(QTcpSocket *socket, QDataStream &in);
        signals:
            /**
              * Emis quand une erreur est survenue
              */
            void errorHappened(QTcpSocket*,QString);
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
            void sendMessage(QString dest, QString contents, QString sender);
            /**
              * Emit quand les informations du serveur doivent être
              * envoyées
              */
            void sendServerData(QTcpSocket *socket);
            /**
              * Emit quand la partie a déjà commencé, à un joueur seulement
              */
            void sendGameHasBegun(QTcpSocket *socket);
            /**
              * Emit quand la partie va commencer à tout les joueurs.
              */
            void sendGameHasBegunToAll();
            /**
              * Emit quand le joueur a demandé ses données
              */
            void sendPlayerData(QTcpSocket *socket);
            /**
              * Emit quand un joueur a été kické.
              * Utilisé par ClientHandler
              */
            void kickPlayer(QString login);
            /**
              * Emit quand un joueur a été kické
              */
            void sendKickMessage(QString login);
    };
}
#endif //SERVER_MESSAGEHANDLER_H
