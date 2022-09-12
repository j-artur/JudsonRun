#ifndef _STUDENT_GENERATOR_H_
#define _STUDENT_GENERATOR_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Student.h"
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

enum StudentsTypes
{
    ABRAAO,
    WILLIAM,
    ARTUR,
    GUILHERM
};

class StudentGenerator : public Object
{
private:
    TileSet* tileSet = nullptr;         // tileset do estudante
    TileSet* tileSet2 = nullptr;
    TileSet* tileSet3 = nullptr;
    TileSet* tileSet4 = nullptr;
    Image* shadow = nullptr;            // sombra do estudante
    float spawnInterval;                // tempo em segundo para aparecer novos estudantes
    float timer;                        // temporizador
    mt19937 rng;                        // gerador de números aleatórios
    uniform_int_distribution<int> posY; // distribuição de números aleatórios para posição y do estudante

public:
    StudentGenerator(Image* studentShadow);
    ~StudentGenerator();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif
