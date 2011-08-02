#ifndef CLIENT_DATAHANDLER_H
#define CLIENT_DATAHANDLER_H
#include <Chunk/Chunk.h>
#include <Map/Entity.h>
#include <QtCore/QObject>
namespace Client
{
    /**
      * Gère les données à disposition du client
      * @brief Gère les données à disposition du client
      * @author Sam101
      */
    class DataHandler : public QObject
    {
        Q_OBJECT
    };
}
#endif //CLIENT_DATAHANDLER_H
