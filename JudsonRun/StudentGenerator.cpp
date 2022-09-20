#include "StudentGenerator.h"

#include <iostream>

StudentGenerator::StudentGenerator(Image *shadow) : shadow(shadow), timer(0.0f)
{
    tileSet = new TileSet("Resources/abraao.png", 64, 96, 2, 4);

    tileSet2 = new TileSet("Resources/william.png", 64, 96, 2, 4);

    tileSet3 = new TileSet("Resources/artur.png", 64, 96, 2, 4);

    tileSet4 = new TileSet("Resources/guilerm.png", 64, 96, 2, 4);

    random_device rd;
    rng.seed(rd());

    posY = uniform_int_distribution<int>(64, window->Height() / 2 - 32);

    spawnInterval = 1.5f;
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
    timeElapsed += gameTime;

    if (timer > spawnInterval)
    {
        uniform_int_distribution<int> rdm(0, 3);
        uniform_int_distribution<int> rdm2(0, 1);
        int studentNumber = rdm(rng);
        int direction = rdm2(rng);

        switch (studentNumber)
        {
        case ABRAAO: {
            if (direction == WLEFT)
            {
                Student *student = new Student(tileSet, shadow, 0, posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            else
            {
                Student *student = new Student(tileSet, shadow, window->Width(), posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            break;
        }
        case WILLIAM: {
            if (direction == WLEFT)
            {
                Student *student = new Student(tileSet2, shadow, 0, posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            else
            {
                Student *student = new Student(tileSet2, shadow, window->Width(), posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            break;
        }
        case ARTUR: {
            if (direction == WLEFT)
            {
                Student *student = new Student(tileSet3, shadow, 0, posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            else
            {
                Student *student = new Student(tileSet3, shadow, window->Width(), posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            break;
        }
        case GUILHERM: {
            if (direction == WLEFT)
            {
                Student *student = new Student(tileSet4, shadow, 0, posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            else
            {
                Student *student = new Student(tileSet4, shadow, window->Width(), posY(rng) * 2, direction);
                JudsonRun::scene->Add(student, MOVING);
            }
            break;
        }
        }
        // Student* student = new Student(tileSet, shadow, 0, posY(rng) * 2);
        // JudsonRun::scene->Add(student, MOVING);

        while (timer > spawnInterval)
            timer -= spawnInterval;
    }

    if (timeElapsed > 5.0f && spawnInterval > 0.25f)
    {
        spawnInterval -= 0.1f;
        timeElapsed -= 5.0f;
    }
}

void StudentGenerator::Draw()
{
}
