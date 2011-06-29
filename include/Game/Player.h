#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <Map/Entity.h>

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
              * Indique si le joueur est actuellement connecté.
              */
            bool _isOnline;
            /**
              * Entités possédées par le joueur
              */
            QList<qint32> _entities;
        public:
            /**
              * Constructeur
              */
            Player(qint32 id, QString login);
            /**
              * Renvoie l'id du joueur
              */
            qint32 getId() const;
            /**
              * Renvoie le login du joueur
              */
            QString getLogin() const;
            /**
              * Renvoie si le joueur est connecté
              */
            bool isOnline() const;
            /**
              * Indique que le joueur est hors ligne
              */
            void setOffline();
            /**
              * Indique que le joueur est à nouveau en ligne
              */
            void setOnline();

    };
}
#endif //GAME_PLAYER_H
