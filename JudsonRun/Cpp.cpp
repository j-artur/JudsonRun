#include "Cpp.h"

Cpp::Cpp(TileSet *tileset, Image *shadowImg, int x, int targetY) : targetY(targetY)
{
    type = CPP;

    anim = new Animation(tileset, 0.2f, true);
    shadow = new Sprite(shadowImg);

    BBox(new Rect(-30.0f, -32.0f, 26.0f, 30.0f));
    MoveTo(float(x), -128.0f);
}

Cpp::~Cpp()
{
    delete anim;
}

void Cpp::Update()
{
    if (falling)
    {
        Translate(0, 200 * gameTime);

        if (y >= targetY)
        {
            MoveTo(x, float(targetY));
            falling = false;
        }
    }
    else
    {
        timer += gameTime;

        if (timer > 10.0f)
        {
            JudsonRun::scene->Delete();
        }
    }

    anim->NextFrame();
}

void Cpp::Draw()
{
    shadow->Draw(float(int(x)), float(targetY + 32), Layer::LOWER);
    anim->Draw(float(int(x)), float(int(y)), 0.9f - (targetY / float(window->Height())) * 0.8f);
}
