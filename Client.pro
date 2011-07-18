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
    include/Client/ConnectionHandler.h

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
    src/Client/ConnectionHandler.cpp
