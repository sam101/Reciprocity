#include <Client/ConnectionHandler.h>
namespace Client
{
    /**
      * Constructeur
      */
    ConnectionHandler::ConnectionHandler() :
    _socket(NULL)
    {

    }
    /**
      * Méthode lançant une tentative de connexion à un serveur
      * et une tentative d'authentification
      */
    void ConnectionHandler::startConnection(QString address, qint32 port, QString login, QString path)
    {
        //On vérifie qu'il n'ya pas une connexion en cours
        //On vérifie le port
        if (port < 0 || port > 65535)
        {
            emit badPort();
            return;
        }
        //On crée le socket.
        _socket = new QTcpSocket(this);
        //On tente la connexion.
        _socket->connectToHost(address,port);
        //On connecte au slots.


    }
}
