#ifndef _CPP_GENERATOR_H_
#define _CPP_GENERATOR_H_

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

class CppGenerator : public Object
{
  private:
    TileSet *tileSet = nullptr;
    Image *shadow = nullptr;
    float timer;
    float spawnInterval;
    float timeElapsed;
    mt19937 rng;
    uniform_int_distribution<int> posX;
    uniform_int_distribution<int> posY;

  public:
    CppGenerator(Image *cppShadow);
    ~CppGenerator();

    void Update();
    void Draw();
};

#endif
