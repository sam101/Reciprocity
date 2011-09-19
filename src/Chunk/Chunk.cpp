#include <Chunk/Chunk.h>
#include <Config/BaseConfig.h>
#include <Config/OutputConfig.h>
#include <QtCore/QDebug>
using namespace Config;
namespace Chunk
{
    /**
      * Constructeur
      */
    Chunk::Chunk(qint32 x, qint32 y, ChunkType type) :
    _x(x),
    _y(y),
    _type(type)
    {
        int signX = x >= 0 ? 1 : -1;
        int signY = y >= 0 ? 1 : -1;
        /*
         * On construit le tableau de tiles
         */
        _tiles.resize(BaseConfig::CHUNK_SIZE);
        for (int i = 0; i < _tiles.size(); i++)
        {
            _tiles[i].resize(BaseConfig::CHUNK_SIZE);
            for (int j = 0; j < _tiles[i].size(); j++)
            {
                _tiles[i][j] = Map::Tile(signX * j  + _x,signY * i + _y,0,Map::NOTHING);
            }
        }
        /*
          * On construit le tableau de batiments
          */
        _buildings.resize(BaseConfig::CHUNK_SIZE);
        for (int i = 0; i < _tiles.size(); i++)
        {
            _buildings[i].resize(BaseConfig::CHUNK_SIZE);
            for (int j = 0; j < _buildings[i].size(); j++)
            {
                _buildings[i][j] = Map::Building(signX * j + _x,signY * i + _y);
            }
        }
    }
    /**
      * Met à jour un chunk
      */
    void Chunk::update(const Chunk &chunk)
    {
        *this = chunk;
    }

    /**
      * Renvoie le type du chunk
      */
    ChunkType Chunk::getType() const
    {
        return _type;
    }
    /**
      * Renvoie la position x du chunk
      */
    qint32 Chunk::getX() const
    {
        return _x;
    }
    /**
      * Renvoie la position y du chunk
      */
    qint32 Chunk::getY() const
    {
        return _y;
    }
    /**
      * Renvoie une tile du chunk
      */
    Map::Tile& Chunk::getTile(qint32 x, qint32 y)
    {
        return _tiles[abs(y - _y)][abs(x - _x)];
    }
    /**
      * Renvoie une tile du chunk.
      * surchargé constant.
      */
    const Map::Tile& Chunk::getTile(qint32 x, qint32 y) const
    {
        return _tiles[abs(y - _y)][abs(x - _x)];
    }
    /**
      * Renvoie une tile du chunk en position absolue
      */
    Map::Tile& Chunk::getTileAbs(qint32 x, qint32 y)
    {
        return _tiles[y][x];
    }
    /**
      * Renvoie une tile du chunk en position absolue
      * surchargé constant.
      */
    const Map::Tile& Chunk::getTileAbs(qint32 x, qint32 y) const
    {
        return _tiles[y][x];
    }
    /**
      * Renvoie un batiment du chunk
      */
    Map::Building& Chunk::getBuilding(qint32 x, qint32 y)
    {
        return _buildings[abs(y - _y)][abs(x - _x)];
    }
    /**
      * Renvoie un batiment du chunk.
      * Surchargé constant
      */
    const Map::Building& Chunk::getBuilding(qint32 x, qint32 y) const
    {
        return _buildings[abs(y - _y)][abs(x - _x)];
    }
    /**
      * Renvoie un batiment du chunk en position absolue
      */
    Map::Building& Chunk::getBuildingAbs(qint32 x, qint32 y)
    {
        return _buildings[y][x];
    }
    /**
      * Renvoie un batiment du chunk en position absolue
      * Surchargé constant
      */
    const Map::Building& Chunk::getBuildingAbs(qint32 x, qint32 y) const
    {
        return _buildings[y][x];
    }
    /**
      * Renvoie la liste des entités présentes sur le chunk
      * surchargé constant
      */
    const QSet<qint32>& Chunk::getEntities() const
    {
        return _entities;
    }
    /**
      * Définit le type du chunk
      */
    void Chunk::setType(ChunkType type)
    {
        _type = type;
    }
    /**
      * Ajoute une entité au chunk
      */
    void Chunk::addEntity(qint32 id)
    {
        if (!_entities.contains(id))
        {
            _entities.insert(id);
        }
    }
    /**
      * Supprime une entité du chunk
      */
    void Chunk::delEntity(qint32 id)
    {
        if (_entities.contains(id))
        {
            _entities.remove(id);
        }
    }
    /**
      * Renvoie si l'entité fait partie du chunk
      */
    bool Chunk::hasEntity(qint32 id) const
    {
        return _entities.contains(id);
    }
    /**
      * Executé au début d'un tour.
      * Restaure la productivité des tiles, et
      * avance la construction des batiments
      */
    void Chunk::newTurn(qint32 outputToRestore)
    {
        //TODO: A déporter ailleurs
        qint32 buildAdvance;
        for (int i = 0; i < BaseConfig::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < BaseConfig::CHUNK_SIZE; j++)
            {
                //On restaure la productivité
                if (_tiles[i][j].getOutput() > OutputConfig::OUTPUT_MINIMAL)
                {
                    _tiles[i][j].restoreOutput(outputToRestore);
                }
                //On avance la construction des batiments
                switch (_buildings[i][j].getType())
                {
                    case Map::HOUSE:
                        buildAdvance = Config::Config::LIFE_HOUSE_BUILD;
                    break;
                    case Map::ROAD:
                        buildAdvance = Config::Config::LIFE_ROAD_BUILD;
                    break;
                    case Map::FARMLAND:
                        buildAdvance = Config::Config::LIFE_FARMLAND_BUILD;
                    break;
                    default:
                        buildAdvance = 1;
                    break;
                }
                _buildings[i][j].advanceBuild(buildAdvance);
            }
        }
    }

    /**
      * Stocke un chunk dans un QDataStream
      */
    QDataStream& operator<<(QDataStream &out, const Chunk &c)
    {
        out << Chunk::CHUNK_MAGICNUMBER;
        out << Chunk::CHUNK_VERSION;
        out << c._x;
        out << c._y;
        out << (qint32)c._type;
        out << c._tiles;
        out << c._buildings;
        out << c._entities;

        return out;
    }
    /**
      * Recupère un chunk d'un QDataStream
      */
    QDataStream& operator>>(QDataStream &in, Chunk &c)
    {
        //On vérifie le magic number
        qint32 magicNumber;
        in >> magicNumber;
        Q_ASSERT(magicNumber == Chunk::CHUNK_MAGICNUMBER);
        //On vérifie la version
        qint32 version;
        in >> version;
        Q_ASSERT(version == Chunk::CHUNK_VERSION);
        //On recupère les données
        in >> c._x;
        in >> c._y;
        in >> (qint32&)c._type;
        in >> c._tiles;
        in >> c._buildings;
        in >> c._entities;

        return in;
    }
}
