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
        if (_socket != NULL)
        {
            _socket->close();
            delete _socket;
        }
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
        //On connecte pour les erreurs
        connect(_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(handleError(QAbstractSocket::SocketError)));
        //On connecte les signaux d'état
        connect(_socket,SIGNAL(hostFound()),this,SLOT(hostFoundHandler()));
        connect(_socket,SIGNAL(connected()),this,SLOT(connectedHandler()));
    }
    /**
      * Gère les erreurs.
      */
    void ConnectionHandler::handleError(QAbstractSocket::SocketError error)
    {
        //On gère tout les cas possibles.
        switch(error)
        {
           case QAbstractSocket::ConnectionRefusedError:
                emit connectionRefused();
           break;

            case QAbstractSocket::HostNotFoundError:
                emit hostnameNotFound();
            break;
            default:
                emit unknownError();
        }
    }
    /**
      * Envoyé quand le chemin à pu être resolu.
      */
    void ConnectionHandler::hostFoundHandler()
    {
        emit hostFound();
    }
    /**
      * Appelé quand la connexion a été établie
      */
    void ConnectionHandler::connectedHandler()
    {
        emit connectedToServer();
    }
}
