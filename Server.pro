#-------------------------------------------------
#
# Project created by QtCreator 2011-06-25T18:39:10
#
#-------------------------------------------------

QT       += core

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
    src/Chunk/SeaChunkGenerator.cpp

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
    include/Chunk/SeaChunkGenerator.h
