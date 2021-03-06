#ifndef SERVER_MESSAGESENDER_H
#define SERVER_MESSAGESENDER_H
#include <Game/Game.h>
#include <Network/AbstractMessage.h>
#include <Server/Client.h>

#include <QtNetwork/QTcpSocket>

#include <QtCore/QMap>
#include <QtCore/QObject>
namespace Server
{
    /**
      * S'occupe d'envoyer les différants messages aux clients
      * @brief S'occupe d'envoyer les différants messages aux clients
      * @author Sam101
      */
    class MessageSender : public QObject
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
        public:
            /**
              * Constructeur
              */
            MessageSender(QMap<QTcpSocket*,Client*> &clients);
            /**
              * Change l'objet de jeu actuel
              */
            void setGame(Game::Game *game);
        public slots:            
            /**
              * Envoie un message comme quoi le login demandé par le client
              * existe déjà
              */
            void sendLoginAlreadyExists(QTcpSocket *socket, QString login);
            /**
              * Envoie un message au client comme quoi un login à réussi
              */
            void sendLoginSuccess(QTcpSocket *socket, qint32 id, bool isAdmin);
            /**
              * Envoie un message aux clients
              */
            void sendChatMessage(QString dest, QString contents, QString sender);
            /**
              * Envoie les informations du serveur à un client
              */
            void sendServerData(QTcpSocket *socket);
            /**
              * Envoie les informations du serveur à tous
              */
            void sendServerDataToAll();
            /**
              * Envoie le message de début de partie à un client
              */
            void sendGameHasBegun(QTcpSocket *socket);
            /**
              * Envoie le message de début de partie à tout les clients
              */
            void sendGameHasBegunToAll();
            /**
              * Envoie les informations sur un chunk
              */
            void sendChunkData(QTcpSocket *socket, Chunk::Chunk *chunk);
            /**
              * Envoie les informations sur une entité
              */
            void sendEntityData(QTcpSocket *socket, Map::Entity *entity);
            /**
              * Envoie les informations sur une entité à tout ceux qui peuvent la voir
              */
            void sendEntityDataToAll(Map::Entity *entity);
            /**
              * Envoie les informations à un joueur sur les chunk qu'il peut
              * voir ainsi que sur ses entités
              */
            void sendPlayerData(QTcpSocket *socket);
            /**
              * Envoie une information comme quoi un joueur a été kické
              */
            void sendKickMessage(QString login);
            /**
              * Envoie l'information comme quoi une entité à bougé
              */
            void sendEntityHasMoved(QTcpSocket *socket, Map::Entity *entity);
            /**
              * Envoie l'information de nouveau tour aux joueurs
              */
            void sendNewTurnToAll();
            /**
              * Envoie les informations  à tout les joueurs
              */
            void sendPlayerDataToAll();
            /**
              * Envoie les informations sur le fait qu'un batiment a été construit au joueur
              */
            void sendBuildingBuilt(QTcpSocket *socket, qint32 entityId);
            /**
              * Envoie les informations sur le fait qu'un travail a été accepté
              */
            void sendWorkAccepted(QTcpSocket *socket, qint32 entityId);
    };
}
#endif //SERVER_MESSAGESENDER_H
