#ifndef _CPP_GENERATOR_H_
#define _CPP_GENERATOR_H_

// ---------------------------------------------------------------------------------
// Inclusões

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
    float spawnInterval;                // tempo em segundo para criação de cpps
    float timeElapsed;
    mt19937 rng;                        // gerador de números aleatórios
    uniform_int_distribution<int> posX; // distribuição de números aleatórios para posição x do cpp
    uniform_int_distribution<int> posY; // distribuição de números aleatórios para posição y final do cpp

  public:
    CppGenerator(Image *cppShadow);
    ~CppGenerator();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif
