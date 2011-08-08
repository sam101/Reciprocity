    #ifndef GAME_GAME_H
#define GAME_GAME_H
#include <QtCore/QObject>
#include <QtCore/QString>
#include <Game/Player.h>
#include <World/World.h>
namespace Game
{
    /**
      * Gère toutes les actions liées aux jeu: Gestion du monde
       *, de ce que contient le monde, des actions, des joueurs
       * @brief Gère toutes les actions liées au jeu
       * @author Sam101
       */
    class Game : public QObject
    {
        Q_OBJECT
        protected:
            /**
              * Pointeur vers le monde
              */
            World::World *_world;
            /**
              * Tableau des joueurs
              */
            QList<Player*> _players;
            /**
              * Indique si la partie à commencé
              */
            bool _hasBegun;
        public:
            /**
              * Constructeur
              */
            Game();
            /**
              * Destructeur
              */
            virtual ~Game();
            /**
              * Renvoie le monde actuel
              */
            World::World* getWorld();
            /**
              * Renvoie le monde actuel
              * surchargé constant
              */
            const World::World* getWorld() const;
            /**
              * Renvoie si la partie a commencé
              */
            bool hasBegun() const;
            /**
              * Ajoute un joueur à la partie
              */
            Player* addPlayer(QString login, QString hash);
            /**
              * Renvoie si le joueur existe
              */
            bool playerExists(QString login) const;
            /**
              * Cherche un joueur dans la liste des joueurs
              */
            Player* findPlayer(QString login) const;
            /**
              * Re-loggue un joueur qui était déjà deconnecté.
              * Renvoie true si l'opération à réussi.
              */
            bool playerBack(QString login, QString hash);
            /**
              * Déplace une entité.
              * @return Vrai si réussi, faux si raté.
              */
            bool moveEntity(qint32 id, qint32 x, qint32 y, qint32 applicant);
            /**
              * Commence un nouveau tour
              */
            void newTurn();
        protected:
            /**
              * Renvoie si le joueur peut être administrateur
              */
            bool canBeAdmin(QString login, QString hash);
            /**
              * Ajoute les entités de base à un joueur
              */
            void addStartEntities(Player *player);
    };
}
#endif //GAME_GAME_H
