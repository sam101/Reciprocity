#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <Map/Entity.h>

#include <QtCore/QDataStream>
#include <QtCore/QString>
namespace Game
{
    /**
      * Gère les informations liées à un joueur dans une partie
      * @brief Gère les informations liées à un joueur dans une partie
      * @author Sam101
      */
    class Player
    {
        public:
            /**
              * MagicNumber de Player
              */
            static const qint32 MAGICNUMBER_PLAYER = 0x4242;
        protected:
            /**
              * Id du joueur
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
              * Dernier temps à laquelle le Player a envoyé un message
              */
            qint64 _lastTime;
            /**
              * Indique si le joueur est actuellement connecté.
              */
            bool _isOnline;
            /**
              * Indique si le joueur est administrateur ou non
              */
            bool _admin;
            /**
              * Indique si le joueur à fini son tour
              */
            bool _endTurn;
            /**
              * Entités possédées par le joueur
              */
            QList<qint32> _entities;
        public:
            /**
              * Constructeur
              */
            Player(qint32 id, QString login, QString hash);
            /**
              * Renvoie l'id du joueur
              */
            qint32 getId() const;
            /**
              * Renvoie le login du joueur
              */
            QString getLogin() const;
            /**
              * Renvoie le hash du joueur
              */
            QString getHash() const;
            /**
              * Renvoie la date a laquelle le joueur a envoyé un message
              */
            qint64 getLastTime() const;
            /**
              * Renvoie si le joueur a fini son tour
              */
            bool hasEndTurn() const;
            /**
              * Renvoie les entités du joueur
              */
            QList<qint32>& getEntities();
            /**
              * Renvoie les entités du joueur.
              * Surchargé constant
              */
            const QList<qint32>& getEntities() const;
            /**
              * Renvoie si le joueur est connecté
              */
            bool isOnline() const;
            /**
              * Renvoie si le joueur est administrateur
              */
            bool isAdmin() const;
            /**
              * Indique que le joueur est hors ligne
              */
            void setOffline();
            /**
              * Indique que le joueur est à nouveau en ligne
              */
            void setOnline();
            /**
              * Change les droits d'administration du joueur
              */
            void setAdmin(bool admin);
            /**
              * Met à jour le lastTime du Joueur.
              */
            void resetLastTime();
            /**
              * Change le fait que le joueur aie fini son tour ou non
              */
            void setEndTurn(bool endTurn = true);
            /**
              * Remet à zéro le fait que le joueur aie fini son tour
              */
            void resetEndTurn();
            /**
              * Ajoute une entité au joueur
              */
            void addEntity(qint32 id);
            /**
              * Envoie le Player dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const Player &p);
            /**
              * Recupère le Player d'un QDataStream
              */
            friend QDataStream& operator>>(QDataStream &in, Player &p);

    };
}
#endif //GAME_PLAYER_H
