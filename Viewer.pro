QT       += core gui


TARGET = Viewer
CONFIG   += console

TEMPLATE = app

INCLUDEPATH += include

SOURCES += \
    src/Chunk/Chunk.cpp \
    src/Map/Entity.cpp \
    src/Map/Tile.cpp \
    src/Viewer/main.cpp

HEADERS += \
    include/Chunk/Chunk.h \
    include/Map/Entity.h \
    include/Map/Tile.h \
    include/Map/TileType.h
