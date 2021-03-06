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
            /**
              * Gère la reception d'une demande de déplacement
              */
            void handleMoveUnit(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'un message de fin de tour
              */
            void handleEndTurn(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'une demande de construction
              */
            void handleBuild(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'une demande de travail
              */
            void handleWork(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'un message d'attaque
              */
            void handleAttack(QTcpSocket *socket, QDataStream &in);
            /**
              * Gère la reception d'un message de suppression
              */
            void handleDelete(QTcpSocket *socket, QDataStream &in);
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
              * Emit quand les informations du serveur doivent être renvoyés à tous
              */
            void sendServerDataToAll();
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
            /**remière étape ->
              * Emit quand un joueur a été kické
              */
            void sendKickMessage(QString login);
            /**
              * Emit quand une entité a bougé
              */
            void entityMoved(QTcpSocket *socket, Map::Entity *entity);
            /**
              * Emit quand le tour à fini
              */
            void sendNewTurnToAll();
            /**
              * Demande de renvoyer les données d'entités à tous
              */
            void sendPlayerDataToAll();
            /**
              * Emit quand un batiment a bien été construit
              */
            void buildingBuilt(QTcpSocket *socket, qint32 entityId);
            /**
              * Emit quand un travail d'entité a été accepté
              */
            void workAccepted(QTcpSocket *socket, qint32 entityId);
            /**
              * Emit quand une attaque a été éffectuée
              */
            void attackAccepted(QTcpSocket *socket, qint32 entityId, qint32 x, qint32 y);
            /**
              * Emit quand une entité à été supprimée
              */
            void entityKilled(QTcpSocket *socket, qint32 entityId);
    };
}
#endif //SERVER_MESSAGEHANDLER_H
