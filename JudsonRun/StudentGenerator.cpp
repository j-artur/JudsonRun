#include "StudentGenerator.h"

#include <iostream>

StudentGenerator::StudentGenerator(Image* shadow) : shadow(shadow), timer(0.0f)
{
    tileSet = new TileSet("Resources/abraao.png", 64, 96, 2, 4);

    tileSet2 = new TileSet("Resources/william.png", 64, 96, 2, 4);

    tileSet3 = new TileSet("Resources/artur.png", 64, 96, 2, 4);

    tileSet4 = new TileSet("Resources/guilerm.png", 64, 96, 2, 4);

    random_device rd;
    rng.seed(rd());

    posY = uniform_int_distribution<int>(80, window->Height() / 2 - 15);

    spawnInterval = 0.5f;
}

StudentGenerator::~StudentGenerator()
{
    delete tileSet;
    delete tileSet2;
    delete tileSet3;
    delete tileSet4;
}

void StudentGenerator::Update()
{
    timer += gameTime;

    if (timer > spawnInterval)
    {
        uniform_int_distribution<int> rdm(0, 3);
        int studentNumber = rdm(rng);

        switch (studentNumber) {
            case ABRAAO:
            {
                Student* student = new Student(tileSet, shadow, 0, posY(rng) * 2);
                JudsonRun::scene->Add(student, MOVING);
                break;
            }
            case WILLIAM:
            {
                Student* student = new Student(tileSet2, shadow, 0, posY(rng) * 2);
                JudsonRun::scene->Add(student, MOVING);
                break;
            }
            case ARTUR:
            {
                Student* student = new Student(tileSet3, shadow, 0, posY(rng) * 2);
                JudsonRun::scene->Add(student, MOVING);
                break;
            }
            case GUILHERM:
            {
                Student* student = new Student(tileSet4, shadow, 0, posY(rng) * 2);
                JudsonRun::scene->Add(student, MOVING);
                break;
            }
        }
        //Student* student = new Student(tileSet, shadow, 0, posY(rng) * 2);
        //JudsonRun::scene->Add(student, MOVING);

        while (timer > spawnInterval)
            timer -= spawnInterval;
    }
}

void StudentGenerator::Draw()
{
}
