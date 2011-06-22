QT       += core gui


TARGET = Viewer
CONFIG   += console

TEMPLATE = app

INCLUDEPATH += include

SOURCES += \
    src/Chunk/Chunk.cpp \
    src/Map/Entity.cpp \
    src/Map/Tile.cpp \
    src/Viewer/main.cpp \
    src/World/World.cpp \
    src/Chunk/ChunkGenerator.cpp \
    src/World/WorldGenerator.cpp \
    src/Chunk/SeaChunkGenerator.cpp \
    src/Tools/Random.cpp \
    src/Chunk/LandChunkGenerator.cpp \
    src/Viewer/ViewerScene.cpp \
    src/Viewer/ViewerView.cpp \
    src/Graphics/TileChunkItem.cpp \
    src/Graphics/Provider.cpp

HEADERS += \
    include/Chunk/Chunk.h \
    include/Map/Entity.h \
    include/Map/Tile.h \
    include/Map/TileType.h \
    include/Config/Config.h \
    include/World/World.h \
    include/Chunk/ChunkType.h \
    include/Chunk/ChunkGenerator.h \
    include/World/WorldGenerator.h \
    include/Chunk/SeaChunkGenerator.h \
    include/Tools/Random.h \
    include/Chunk/LandChunkGenerator.h \
    include/Viewer/ViewerScene.h \
    include/Viewer/ViewerView.h \
    include/Graphics/TileChunkItem.h \
    include/Graphics/Provider.h \
    include/Map/EntityAbilities.h
