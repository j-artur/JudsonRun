#ifndef _CPP_GENERATOR_H_
#define _CPP_GENERATOR_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Cpp.h"
#include "JudsonRun.h"
#include "Object.h"
#include "Scene.h"
#include "TileSet.h"
#include "Timer.h"

#include <random>

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

// ------------------------------------------------------------------------------

class CppGenerator : public Object
{
  private:
    TileSet *tileSet = nullptr;         // tileset do cpp
    Image *shadow = nullptr;            // sombra do cpp
    float timer;                        // temporizador
    float spawnInterval;                // tempo em segundo para cria��o de cpps
    float timeElapsed;
    mt19937 rng;                        // gerador de n�meros aleat�rios
    uniform_int_distribution<int> posX; // distribui��o de n�meros aleat�rios para posi��o x do cpp
    uniform_int_distribution<int> posY; // distribui��o de n�meros aleat�rios para posi��o y final do cpp

  public:
    CppGenerator(Image *cppShadow);
    ~CppGenerator();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif
