#include "StudentGenerator.h"

#include <iostream>

StudentGenerator::StudentGenerator(Image* shadow) : shadow(shadow), timer(0.0f)
{
    tileSet = new TileSet("Resources/guilerm.png", 64, 96, 2, 4);

    random_device rd;
    rng.seed(rd());

    posY = uniform_int_distribution<int>(80, window->Height() / 2 - 15);

    spawnInterval = 0.5f;
}

StudentGenerator::~StudentGenerator()
{
    delete tileSet;
}

void StudentGenerator::Update()
{
    timer += gameTime;

    if (timer > spawnInterval)
    {
        Student* student = new Student(tileSet, shadow, 0, posY(rng) * 2);
        JudsonRun::scene->Add(student, MOVING);

        while (timer > spawnInterval)
            timer -= spawnInterval;
    }
}

void StudentGenerator::Draw()
{
}
