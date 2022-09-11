#include "Judson.h"

Judson::Judson(Image *shadowImg)
{
    type = PLAYER;

    tileSet = new TileSet("Resources/judson.png", 64, 96, 2, 4);
    anim = new Animation(tileSet, 0.2f, true);

    shadow = new Sprite(shadowImg);

    speed = 300.0f;

    BBox(new Rect(-20.0f, -34.0f, 14.0f, 48.0f));
}

Judson::~Judson()
{
    delete shadow;
    delete anim;
    delete tileSet;
}

void Judson::Update()
{
    if (window->KeyDown(VK_LEFT))
        left = true;
    if (window->KeyDown(VK_RIGHT))
        right = true;
    if (window->KeyDown(VK_UP))
        up = true;
    if (window->KeyDown(VK_DOWN))
        down = true;
    if (window->KeyUp(VK_LEFT))
        left = false;
    if (window->KeyUp(VK_RIGHT))
        right = false;
    if (window->KeyUp(VK_UP))
        up = false;
    if (window->KeyUp(VK_DOWN))
        down = false;

    if (left && !right && !up && !down)
        Translate(-speed * gameTime, 0.0f);
    else if (!left && right && !up && !down)
        Translate(speed * gameTime, 0.0f);
    else if (!left && !right && up && !down)
        Translate(0.0f, -speed * gameTime);
    else if (!left && !right && !up && down)
        Translate(0.0f, speed * gameTime);
    else if (left && !right && up && !down)
        Translate(-(speed / float(sqrt(2.0))) * gameTime, -(speed / float(sqrt(2.0))) * gameTime);
    else if (left && !right && !up && down)
        Translate(-(speed / float(sqrt(2.0))) * gameTime, (speed / float(sqrt(2.0))) * gameTime);
    else if (!left && right && up && !down)
        Translate((speed / float(sqrt(2.0))) * gameTime, -(speed / float(sqrt(2.0))) * gameTime);
    else if (!left && right && !up && down)
        Translate((speed / float(sqrt(2.0))) * gameTime, (speed / float(sqrt(2.0))) * gameTime);
    else if (left && !right && up && down)
        Translate(-speed * gameTime, 0.0f);
    else if (!left && right && up && down)
        Translate(speed * gameTime, 0.0f);
    else if (left && right && up && !down)
        Translate(0.0f, -speed * gameTime);
    else if (left && right && !up && down)
        Translate(0.0f, speed * gameTime);

    if (powered)
    {
        poweredTime -= gameTime;

        if (poweredTime <= 0.0f)
            powered = false;
    }

    anim->NextFrame();
}

void Judson::OnCollision(Object *other)
{
    if (other->Type() == ENEMY)
    {
        // game over
    }

    if (other->Type() == CPP && !((Cpp *)other)->Falling())
    {
        powered = true;
        poweredTime = 10.0f;

        JudsonRun::scene->Delete(other, MOVING);
    }
}

void Judson::Draw()
{
    shadow->Draw(x, y + 48, Layer::LOWER);
    anim->Draw(x, y, Layer::FRONT);
}
