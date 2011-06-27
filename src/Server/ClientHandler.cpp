#include <Server/ClientHandler.h>
#include <QtCore/QDebug>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
namespace Server
{
    /**
      * Constructeur
      */
    ClientHandler::ClientHandler()
    {

    }
    /**
      * Appelé quand un client se connecte au serveur.
      * Envoie la connexion au serveur si celle-ci
      * n'est pas filtrée
      */
    void ClientHandler::handleIncomming()
    {
        //On recupère le socket server
        QTcpServer *server = qobject_cast<QTcpServer*>(sender());
        //Si ce n'est pas un socket qui a envoyé
        if (server == NULL)
        {
            qDebug() << "ClientHandler::handleIncomming: Erreur, socket serveur incorrect";
            return;
        }
        //On recupère la socket
        QTcpSocket *socket = server->nextPendingConnection();
        //Si la socket n'existe pas, on retourne
        if (socket == NULL)
        {
            return;
        }
        //Sinon, on procède à des vérifications

        //TODO

        //On envoie le signal pour dire qu'il y'a un nouveau client
        emit newClient(socket);
    }
    /**
      * Appelé quand un client se deconnecte du serveur.
      * Envoit un signal pour annoncer que le client
      * s'est déconnecté
      */
    void ClientHandler::handleDisconnection()
    {
        //On vérifie que c'est bien un QTcpSocket qui a envoyé le signal
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        if (socket == NULL)
        {
            return;
        }
        emit clientHasDisconnected(socket);
    }
}
