#include <Chunk/DesertLandChunkGenerator.h>
#include <Tools/Random.h>
using namespace Tools;
namespace Chunk
{
    /**
      * Genère un chunk
      * @param chunk Pointeur vers le chunk a générer (déjà alloué)
      */
    void DesertLandChunkGenerator::generate(Chunk *chunk)
    {
        /*
         * On genère de l'eau sur tout le chunk tout d'abord.
         */
        for (int i = 0; i  < Config::Config::CHUNK_SIZE; i++)
        {
            for (int j = 0; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        /*
          * On genère une plage géante
          */
        int xStart, yStart, xEnd, yEnd;
        xStart = Random::next(0,Config::Config::CHUNK_SIZE / 2);
        yStart = Random::next(0,Config::Config::CHUNK_SIZE / 2);
        xEnd = Random::next(Config::Config::CHUNK_SIZE - 2,Config::Config::CHUNK_SIZE);
        yEnd = Random::next(Config::Config::CHUNK_SIZE - 2,Config::Config::CHUNK_SIZE);
        for (int i = xStart; i <= xEnd; i++)
        {
            for (int j = yStart; j <= yEnd; j++)
            {
                if (Random::next(0,5) == 0)
                {
                    chunk->getTileAbs(i,j).setAsLowLand();
                }
                else
                {
                    chunk->getTileAbs(i,j).setAsBeach();
                }
            }
        }
        //On creuse des trous dans la cote.
        //Cote nord/sud
        int yTopCoast = yStart;
        int yBottomCoast = yEnd;
        for (int i = xStart; i <= xEnd; i++)
        {
            yTopCoast += Random::next(-2,2);
            if (yTopCoast < 0) yTopCoast = 0;
            if (yTopCoast >= Config::Config::CHUNK_SIZE) yTopCoast = Config::Config::CHUNK_SIZE - 1;
            yBottomCoast += Random::next(-2,2);
            if (yBottomCoast < 0) yBottomCoast = 0;
            if (yBottomCoast >= Config::Config::CHUNK_SIZE) yBottomCoast = Config::Config::CHUNK_SIZE - 1;

            for (int j = yBottomCoast; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(i,j).setAsSea();
            }
            for (int j = 0; j <= yTopCoast; j++)
            {
                chunk->getTileAbs(i,j).setAsSea();
            }
        }
        //Cote ouest/est
        int xLeftCoast = xStart;
        int xRightCoast = yEnd;
        for (int i = yStart; i <= yEnd; i++)
        {
            xLeftCoast += Random::next(-2,2);
            xRightCoast += Random::next(-2,2);
            if (xLeftCoast <= 0) xLeftCoast = 0;
            else if (xLeftCoast >= Config::Config::CHUNK_SIZE) xLeftCoast = Config::Config::CHUNK_SIZE - 1;
            if (xRightCoast <= 0) xRightCoast = 0;
            else if (xRightCoast >= Config::Config::CHUNK_SIZE) xRightCoast = Config::Config::CHUNK_SIZE - 1;
            for (int j = xRightCoast; j < Config::Config::CHUNK_SIZE; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
            for (int j = 0; j <= xLeftCoast; j++)
            {
                chunk->getTileAbs(j,i).setAsSea();
            }
        }
        //On ajoute des plaines au milieu
        int nbLowLand = Random::next(0,Config::Config::CHUNK_SIZE * 4);
        int x, y;
        for (int i = 0; i < nbLowLand; i++)
        {
            chunk->getTileAbs(x,y).setAsLowLand();
        }
    }

}
