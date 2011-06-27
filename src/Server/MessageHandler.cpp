#include <Server/MessageHandler.h>
#include <QtNetwork/QTcpSocket>
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
    }
}
