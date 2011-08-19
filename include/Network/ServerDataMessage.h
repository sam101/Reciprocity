#ifndef NETWORK_SERVERDATAMESSAGE_H
#define NETWORK_SERVERDATAMESSAGE_H
#include <Network/AbstractMessage.h>
#include <QtCore/QList>
#include <QtCore/QPair>
namespace Network
{
    /**
      * Données envoyées du serveur au client, contient diverses
      * informations sur le serveur
      * @brief Contient diverses informations sur le serveur
      * @author Sam101
      */
    class ServerDataMessage : public AbstractMessage
    {
        public:
            /**
              * MagicNumber de ServerDataMessage
              */
            static const qint32 MAGICNUMBER_SERVER_DATA = 0x4207;
        protected:
            /**
              * Nom du serveur
              */
            QString _name;
            /**
              * Liste des joueurs sur le serveur
              */
            QList<QPair<QString,bool> > _players;
            /**
              * Numéro de tour du serveur
              */
            qint32 _turn;
        public:
            /**
              * Constructeur
              */
            ServerDataMessage(QString name = "", qint32 turn = 1);
            /**
              * Ajoute un joueur à la liste des joueurs
              */
            void addPlayer(QString login, bool isAdmin);
            /**
              * Renvoie la liste des joueurs
              */
            const QList<QPair<QString,bool> >& getPlayers() const;
            /**
              * Renvoie le numéro de tour du serveur
              */
            qint32 getTurn() const;
            /**
              * Envoie le message dans un QDataStream
              */
            friend QDataStream& operator<<(QDataStream &out, const ServerDataMessage &m);
            /**
              * Recupère le message d'un QDatastream
              */
            friend QDataStream& operator>>(QDataStream &in, ServerDataMessage &m);


    };
}
#endif //NETWORK_SERVERDATAMESSAGE_H
