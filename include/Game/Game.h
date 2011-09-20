    #ifndef GAME_GAME_H
#define GAME_GAME_H
#include <QtCore/QObject>
#include <QtCore/QString>
#include <Game/Player.h>
#include <Map/BuildingType.h>
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
              * Numéro du tour actuel
              */
            qint32 _turn;
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
              * Renvoie le tour actuel
              */
            qint32 getTurn() const;
            /**
              * Renvoie une entité
              */
            Map::Entity* getEntity(qint32 id);
            /**
              * Renvoie un joueur
              */
            Player* getPlayer(qint32 id);
            /**
              * Renvoie un joueur.
              * Surchargé constant
              */
            const Player* getPlayer(qint32 id) const;
            /**
              * Ajoute une entité à la partie
              */
            void addEntity(const Map::Entity &entity, qint32 x, qint32 y);
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
              * Renvoie les chunks sur lequel le joueur est présent
              */
            QSet<Chunk::Chunk*> getPlayerChunks(Player *player);
            /**
              * Renvoie les entités d'un joueur
              */
            QList<Map::Entity*> getPlayerEntities(Player *player, QSet<Chunk::Chunk*> chunks);
            /**
              * Commence la partie
              */
            void beginGame();
            /**
              * Déplace une entité.
              * @return true si réussi, false si impossible.
              */
            bool moveEntity(qint32 id, qint32 x, qint32 y, qint32 applicant);
            /**
              * Construit un batiment
              * @return true si réussi, false si échoué
              */
            bool build(qint32 entityId, Map::BuildingType type);
            /**
              * Fait travailler une entité
              * @return true si réussi, false si impossible
              */
            bool work(qint32 entityId);
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
