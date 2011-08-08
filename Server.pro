QT       += core network

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += include

SOURCES += \
    src/Server/main.cpp \
    src/World/World.cpp \
    src/World/WorldGenerator.cpp \
    src/Tools/Random.cpp \
    src/Map/Building.cpp \
    src/Map/Entity.cpp \
    src/Map/Tile.cpp \
    src/Chunk/Chunk.cpp \
    src/Chunk/ChunkGenerator.cpp \
    src/Chunk/IslandChunkGenerator.cpp \
    src/Chunk/LandChunkGenerator.cpp \
    src/Chunk/SeaChunkGenerator.cpp \
    src/Server/Server.cpp \
    src/Game/Game.cpp \
    src/Server/ClientHandler.cpp \
    src/Server/MessageHandler.cpp \
    src/Network/AbstractMessage.cpp \
    src/Server/Client.cpp \
    src/Game/Player.cpp \
    src/Network/LoginMessage.cpp \
    src/Network/LoginFailedMessage.cpp \
    src/Network/LoginSuccessMessage.cpp \
    src/Server/MessageSender.cpp \
    src/Network/MessageOutMessage.cpp \
    src/Network/MessageInMessage.cpp \
    src/Network/GameHasBegunMessage.cpp \
    src/Network/ServerDataMessage.cpp \
    src/Network/GetServerDataMessage.cpp \
    src/Network/ErrorMessage.cpp \
    src/Network/BeginGameMessage.cpp \
    src/Chunk/DesertLandChunkGenerator.cpp \
    src/Network/RequestDataMessage.cpp \
    src/Network/ChunkDataMessage.cpp \
    src/Network/EntityDataMessage.cpp \
    src/Network/MoveUnitMessage.cpp \
    src/Network/MoveUnitAcceptedMessage.cpp \
    src/Network/KickPlayerMessage.cpp

HEADERS += \
    include/World/World.h \
    include/World/WorldGenerator.h \
    include/Tools/Random.h \
    include/Map/Building.h \
    include/Map/Entity.h \
    include/Map/EntityAbilities.h \
    include/Map/Tile.h \
    include/Map/TileType.h \
    include/Config/Config.h \
    include/Chunk/Chunk.h \
    include/Chunk/ChunkGenerator.h \
    include/Chunk/ChunkType.h \
    include/Chunk/IslandChunkGenerator.h \
    include/Chunk/LandChunkGenerator.h \
    include/Chunk/SeaChunkGenerator.h \
    include/Server/Server.h \
    include/Game/Game.h \
    include/Server/ClientHandler.h \
    include/Server/MessageHandler.h \
    include/Network/MessageType.h \
    include/Network/AbstractMessage.h \
    include/Server/Client.h \
    include/Game/Player.h \
    include/Map/BuildingType.h \
    include/Network/LoginMessage.h \
    include/Network/LoginFailedMessage.h \
    include/Network/LoginSuccessMessage.h \
    include/Server/MessageSender.h \
    include/Network/MessageOutMessage.h \
    include/Network/MessageInMessage.h \
    include/Network/GameHasBegunMessage.h \
    include/Network/ServerDataMessage.h \
    include/Network/GetServerDataMessage.h \
    include/Network/ErrorMessage.h \
    include/Network/BeginGameMessage.h \
    include/Chunk/DesertLandChunkGenerator.h \
    include/Network/RequestDataMessage.h \
    include/Network/ChunkDataMessage.h \
    include/Network/EntityDataMessage.h \
    include/Network/MoveUnitMessage.h \
    include/Network/MoveUnitAcceptedMessage.h \
    include/Network/MoveUnitAcceptedMessage.h \
    include/Network/KickPlayerMessage.h
