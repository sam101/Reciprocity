#include <Game/Game.h>
#include <QtCore/QDebug>
namespace Game
{
    /**
      * Constructeur
      */
    Game::Game() :
    _world(NULL),
    _hasBegun(false)
    {
        //On alloue l'objet de monde
        _world = new World::World;
    }
    /**
      * Destructeur
      */
    Game::~Game()
    {
        if (_world != NULL)
        {
            delete _world;
        }
        for (int i = 0; i < _players.size(); i++)
        {
            delete _players[i];
        }
    }
    /**
      * Renvoie le monde actuel
      */
    World::World* Game::getWorld()
    {
        return _world;
    }
    /**
      * Renvoie le monde actuel
      * Surchargé constant.
      */
    const World::World* Game::getWorld() const
    {
        return _world;
    }
    /**
      * Renvoie si la partie a commencé
      */
    bool Game::hasBegun() const
    {
        return _hasBegun;
    }
    /**
      * Ajoute un joueur à la partie
      */
    Player* Game::addPlayer(QString login, QString hash)
    {
        //On ajoute l'objet "Player"
        _players.append(new Player(_players.size(),login,hash));
        //Si il est le premier joueur, on lui donne les droits d'administrateur.
        if (canBeAdmin(login,hash))
        {
            qDebug() << "Le joueur" << login << "est administrateur";
            _players.last()->setAdmin(true);
        }
        //On lui ajoute ses entités/ressources "de base".
        addStartEntities(_players.last());

        //On renvoie l'objet Player
        return _players.last();
    }
    /**
      * Renvoie si le joueur existe
      */
    bool Game::playerExists(QString login) const
    {
        return findPlayer(login) != NULL;
    }
    /**
      * Cherche un joueur dans la liste des joueurs
      */
    Player* Game::findPlayer(QString login) const
    {
        for (int i = 0; i < _players.size(); i++)
        {
            if (_players[i]->getLogin() == login)
            {
                return _players[i];
            }
        }
        return NULL;
    }

    /**
      * Re-loggue un joueur qui était déjà deconnecté.
      * Renvoie vrai si l'opération à réussi.
      */
    bool Game::playerBack(QString login, QString hash)
    {
        //On recupère un pointeur vers le joueur
        Player *player = findPlayer(login);
        //Si le joueur n'existe pas
        if (player == NULL)
        {
            return false;
        }
        //On vérifie que le hash est bon.
        if (player->getHash() == hash)
        {
            //On indique que le joueur est en ligne
            player->setOnline();
            //On indique que l'opération s'est bien passée
            return true;
        }
        return false;
    }
    /**
      * Renvoie si le joueur peut être administrateur
      */
    bool Game::canBeAdmin(QString login, QString hash)
    {
        Q_UNUSED(login)
        Q_UNUSED(hash)
        //Si il y'a qu'un seul joueur, il est forcément administrateur
        if (_players.size() == 1)
        {
            return true;
        }
        //Enfin, on vérifie si le joueur est seul dans la partie
        int i = 0;
        while (i < _players.size() - 1)
        {
            if (_players[i]->isOnline())
            {
                return false;
            }
            i++;
        }
        //Si on en a trouvé aucun, alors il est bien admin.
        return true;
    }
    /**
      * Ajoute les entités de base à un joueur
      */
    void Game::addStartEntities(Player *player)
    {

    }
}
