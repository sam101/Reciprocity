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
    include/Tools/Random.h

SOURCES += \
    src/Graphics/TileChunkItem.cpp \
    src/Graphics/Provider.cpp \
    src/Map/Tile.cpp \
    src/Map/Entity.cpp \
    src/Map/Building.cpp \
    src/Network/LoginMessage.cpp \
    src/Network/AbstractMessage.cpp \
    src/Tools/Random.cpp \
    src/Client/main.cpp
