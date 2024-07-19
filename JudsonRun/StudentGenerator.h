#ifndef _STUDENT_GENERATOR_H_
#define _STUDENT_GENERATOR_H_

#include "JudsonRun.h"
#include "Object.h"
#include "Scene.h"
#include "Student.h"
#include "TileSet.h"
#include "Timer.h"

#include <random>

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

class StudentGenerator : public Object
{
  private:
    TileSet *tileSet = nullptr;
    TileSet *tileSet2 = nullptr;
    TileSet *tileSet3 = nullptr;
    TileSet *tileSet4 = nullptr;
    Image *shadow = nullptr;
    float spawnInterval;
    float timer;
    float timeElapsed;
    mt19937 rng;
    uniform_int_distribution<int> posY;

  public:
    StudentGenerator(Image *studentShadow);
    ~StudentGenerator();

    void Update();
    void Draw();
};

#endif
