QT       += core network gui
TARGET = Reciprocity
CONFIG   += console
INCLUDEPATH += include
TEMPLATE = app

HEADERS += \
    include/Config/Config.h \
    include/Graphics/TileChunkItem.h \
    include/Graphics/Provider.h \
    include/Map/TileType.h \
    include/Map/Tile.h \
    include/Map/EntityAbilities.h \
    include/Map/Entity.h \
    include/Map/BuildingType.h \
    include/Map/Building.h \
    include/Network/MessageType.h \
    include/Network/LoginMessage.h \
    include/Network/AbstractMessage.h \
    include/Tools/Random.h \
    include/GUI/StartWindow.h \
    include/Chunk/Chunk.h \
    include/Chunk/ChunkType.h \
    include/GUI/JoinGameWindow.h \
    include/Client/Client.h \
    include/Client/ConnectionHandler.h \
    include/GUI/ConnectingWindow.h \
    include/Network/MessageOutMessage.h \
    include/Network/MessageInMessage.h \
    include/Network/GameHasBegunMessage.h \
    include/GUI/WaitingWindow.h \
    include/Network/LoginSuccessMessage.h \
    include/Network/LoginFailedMessage.h \
    include/Network/GetServerDataMessage.h \
    include/Network/ServerDataMessage.h \
    include/Network/ErrorMessage.h \
    include/Network/BeginGameMessage.h \
    include/GUI/GameWindow.h \
    include/Graphics/BuildingChunkItem.h \
    include/Client/DataHandler.h \
    include/GUI/GameScene.h \
    include/Network/RequestDataMessage.h \
    include/Network/ChunkDataMessage.h \
    include/Network/EntityDataMessage.h \
    include/Network/MoveUnitMessage.h \
    include/Network/MoveUnitAcceptedMessage.h \
    include/Network/MoveUnitAcceptedMessage.h \
    include/Network/KickPlayerMessage.h

SOURCES += \
    src/Graphics/TileChunkItem.cpp \
    src/Graphics/Provider.cpp \
    src/Map/Tile.cpp \
    src/Map/Entity.cpp \
    src/Map/Building.cpp \
    src/Network/LoginMessage.cpp \
    src/Network/AbstractMessage.cpp \
    src/Tools/Random.cpp \
    src/Client/main.cpp \
    src/GUI/StartWindow.cpp \
    src/Chunk/Chunk.cpp \
    src/GUI/JoinGameWindow.cpp \
    src/Client/Client.cpp \
    src/Client/ConnectionHandler.cpp \
    src/GUI/ConnectingWindow.cpp \
    src/Network/MessageOutMessage.cpp \
    src/Network/MessageInMessage.cpp \
    src/Network/GameHasBegunMessage.cpp \
    src/GUI/WaitingWindow.cpp \
    src/Network/LoginSuccessMessage.cpp \
    src/Network/LoginFailedMessage.cpp \
    src/Network/GetServerDataMessage.cpp \
    src/Network/ServerDataMessage.cpp \
    src/Network/ErrorMessage.cpp \
    src/Network/BeginGameMessage.cpp \
    src/GUI/GameWindow.cpp \
    src/Graphics/BuildingChunkItem.cpp \
    src/Client/DataHandler.cpp \
    src/GUI/GameScene.cpp \
    src/Network/RequestDataMessage.cpp \
    src/Network/ChunkDataMessage.cpp \
    src/Network/EntityDataMessage.cpp \
    src/Network/MoveUnitMessage.cpp \
    src/Network/MoveUnitAcceptedMessage.cpp \
    src/Network/KickPlayerMessage.cpp
