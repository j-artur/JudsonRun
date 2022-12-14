#include "Student.h"

Student::Student(TileSet *tileset, Image *shadowImg, int x, int y, uint direction, StudentsType studentType)
{
    type = ENEMY;

    anim = new Animation(tileset, 0.2f, true);
    shadow = new Sprite(shadowImg);

    uint SeqLeft[2] = {0, 1};
    uint SeqRight[2] = {2, 3};

    anim->Add(WLEFT, SeqLeft, 2);
    anim->Add(WRIGHT, SeqRight, 2);

    walkingDirection = direction;

    if (x)
    {
        anim->Select(WLEFT);
        walkingDirection = WLEFT;
    }
    else
    {
        anim->Select(WRIGHT);
        walkingDirection = WRIGHT;
    }

    switch (studentType)
    {
    case ABRAAO:
        speed = 200.0f;
        BBox(new Rect(-16.0f, -36.0f, 16.0f, 48.0f));
        break;
    case WILLIAM:
        speed = 250.0f;
        BBox(new Rect(-14.0f, -24.0f, 14.0f, 48.0f));
        break;
    case ARTUR:
        speed = 200.0f;
        BBox(new Rect(-16.0f, -36.0f, 16.0f, 48.0f));
        break;
    case GUILHERM:
        speed = 200.0f;
        BBox(new Rect(-16.0f, -36.0f, 16.0f, 48.0f));
        break;
    }

    MoveTo(float(x), float(y));
}

Student::~Student()
{
    delete anim;
}

void Student::Update()
{
    if (x < -32.0f || x > window->Width() + 32.0f)
    {
        JudsonRun::scene->Delete();
        JudsonRun::panel->AddScore(10);
        return;
    }

    if (walkingDirection)
        Translate(speed * gameTime, 0);
    else
        Translate(-speed * gameTime, 0);

    anim->NextFrame();
}

void Student::Draw()
{
    shadow->Draw(float(int(x)), float(y + 48), Layer::LOWER);
    anim->Draw(float(int(x)), float(int(y)), 0.9f - (y / float(window->Height())) * 0.8f);
}
