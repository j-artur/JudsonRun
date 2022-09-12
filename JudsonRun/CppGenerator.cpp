#include "CppGenerator.h"

#include <iostream>

CppGenerator::CppGenerator(Image *shadow) : shadow(shadow), timer(0.0f)
{
    tileSet = new TileSet("Resources/cpp.png", 64, 64, 2, 2);

    random_device rd;
    rng.seed(rd());
    posX = uniform_int_distribution<int>(15, window->Width() / 2 - 13);
    posY = uniform_int_distribution<int>(16, window->Height() / 2 - 15);

    spawnInterval = 0.5f;
}

CppGenerator::~CppGenerator()
{
    delete tileSet;
}

void CppGenerator::Update()
{
    timer += gameTime;

    if (timer > spawnInterval)
    {
        Cpp *cpp = new Cpp(tileSet, shadow, posX(rng) * 2, posY(rng) * 2);
        JudsonRun::scene->Add(cpp, MOVING);

        while (timer > spawnInterval)
            timer -= spawnInterval;
    }
}

void CppGenerator::Draw()
{
}
