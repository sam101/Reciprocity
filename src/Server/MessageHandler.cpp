#include <Server/MessageHandler.h>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QDataStream>
#include <QtCore/QDebug>
namespace Server
{
    /**
      * Constructeur
      */
    MessageHandler::MessageHandler(Game::Game *game) :
    _game(game)
    {

    }
    /**
      * Appelé lors de la reception d'un message.
      * Detecte le type du message envoyé et
      * appelle la méthode correspondante au message reçu.
      */
    void MessageHandler::messageRecevied()
    {
        //On recupère la socket qui a envoyé le message
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        //On vérifie que la socket existe bien
        if (socket == 0)
        {
            qDebug() << tr("Attention, messageRecevied appelé par autre chose qu'une socket.");
            return;
        }
        //On déclare le datastream pour lire les données
        QDataStream in(socket);
        in.setVersion(QDataStream::Qt_4_5);
        if (_sizes[socket] == 0)
        {
            //On vérifie qu'on a reçu la taille du message.
            if (socket->bytesAvailable() < sizeof(quint16))
            {
                return;
            }
            //On vérifie qu'on à bien tout le message.
            in >> _sizes[socket];
        }
        //Si on a pas tout le message, on abandonne.
        if (socket->bytesAvailable() < _sizes[socket])
        {
            return;
        }
        //On recupère le type du message.
    }
}
