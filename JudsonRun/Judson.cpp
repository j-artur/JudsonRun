#include "Judson.h"

Judson::Judson(Image *shadowImg)
{
    type = PLAYER;

    tileSet = new TileSet("Resources/judson.png", 64, 96, 6, 12);
    anim = new Animation(tileSet, 0.2f, true);

    shadow = new Sprite(shadowImg);

    speed = 300.0f;

    BBox(new Rect(-20.0f, -32.0f, 14.0f, 50.0f));
}

Judson::~Judson()
{
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

    if (left && right)
        left = right = false;
    if (up && down)
        up = down = false;

    float diaSpeed = speed / float(sqrt(2.0));

    if (left && up)
        Translate(-diaSpeed * gameTime, -diaSpeed * gameTime);
    else if (left && down)
        Translate(-diaSpeed * gameTime, diaSpeed * gameTime);
    else if (right && up)
        Translate(diaSpeed * gameTime, -diaSpeed * gameTime);
    else if (right && down)
        Translate(diaSpeed * gameTime, diaSpeed * gameTime);
    else if (left)
        Translate(-speed * gameTime, 0.0f);
    else if (right)
        Translate(speed * gameTime, 0.0f);
    else if (up)
        Translate(0.0f, -speed * gameTime);
    else if (down)
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

        // temporario, so pra testar
        JudsonRun::panel->AddScore(100);

        JudsonRun::scene->Delete(other, MOVING);
    }
}

void Judson::Draw()
{
    shadow->Draw(float(int(x)), float(int(y) + 48), Layer::LOWER);
    anim->Draw(float(int(x)), float(int(y)), 0.9f - (y / float(window->Height())) * 0.8f);
}
