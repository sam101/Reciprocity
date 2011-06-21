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
    src/Tools/Random.cpp

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
    include/Tools/Random.h
