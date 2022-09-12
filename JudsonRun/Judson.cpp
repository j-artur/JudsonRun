#include "Judson.h"

Judson::Judson(Image *shadowImg)
{
    type = PLAYER;

    tileSet = new TileSet("Resources/judson.png", 64, 96, 6, 12);
    anim = new Animation(tileSet, 0.2f, true);

    uint SeqLeft[2] = {0, 1};
    uint SeqRight[2] = {6, 7};
    uint SeqPoweredLeft[4] = {2, 3, 4, 5};
    uint SeqPoweredRight[4] = {8, 9, 10, 11};
    uint SeqStillLeft[1] = {1};
    uint SeqStillRight[1] = {6};
    uint SeqPoweredStillLeft[2] = {3, 5};
    uint SeqPoweredStillRight[2] = {8, 10};

    // normal states
    anim->Add(WALKLEFT, SeqLeft, 2);
    anim->Add(WALKRIGHT, SeqRight, 2);
    anim->Add(STILLEFT, SeqStillLeft, 1);
    anim->Add(STILLRIGHT, SeqStillRight, 1);

    // powered states
    anim->Add(POWEREDLEFT, SeqPoweredLeft, 4);
    anim->Add(POWEREDRIGHT, SeqPoweredRight, 4);
    anim->Add(POWEREDSTILLEFT, SeqPoweredStillLeft, 2);
    anim->Add(POWEREDSTILLRIGHT, SeqPoweredStillRight, 2);

    shadow = new Sprite(shadowImg);

    BBox(new Rect(-16.0f, -36.0f, 16.0f, 48.0f));
}

Judson::~Judson()
{
    delete anim;
    delete tileSet;
}

void Judson::Update()
{

    // mc movements
    if (window->KeyDown(VK_LEFT))
    {
        state = WALKLEFT;
        lastPressed = LEFT;
        left = true;
    }
    if (window->KeyDown(VK_RIGHT))
    {
        state = WALKRIGHT;
        lastPressed = RIGHT;
        right = true;
    }
    if (window->KeyDown(VK_UP))
    {
        if (lastPressed)
            state = WALKRIGHT;
        else
            state = WALKLEFT;
        up = true;
    }
    if (window->KeyDown(VK_DOWN))
    {
        if (lastPressed)
            state = WALKRIGHT;
        else
            state = WALKLEFT;
        down = true;
    }
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

    if (!up && !down && !left && !right)
    {
        if (lastPressed)
            state = STILLRIGHT;
        else
            state = STILLEFT;
    }

    // when powered change to powered states
    if (powered)
    {
        switch (state)
        {
        case STILLRIGHT:
            state = POWEREDSTILLRIGHT;
            break;
        case STILLEFT:
            state = POWEREDSTILLEFT;
            break;
        case WALKLEFT:
            state = POWEREDLEFT;
            break;
        case WALKRIGHT:
            state = POWEREDRIGHT;
            break;
        }
    }

    // two buttons on the same time handling
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

    // maintain mc on the screen
    if (x + tileSet->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - tileSet->TileWidth() / 2.0f, y);

    if (x - tileSet->TileWidth() / 2.0f < 0)
        MoveTo(tileSet->TileWidth() / 2.0f, y);

    if (y + tileSet->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - tileSet->TileHeight() / 2.0f);

    if (y - tileSet->TileHeight() / 2.0f < 80)
        MoveTo(x, tileSet->TileHeight() / 2.0f + 80);

    // powered timer
    if (powered)
    {
        poweredTime -= gameTime;

        if (poweredTime <= 0.0f)
            powered = false;
    }

    anim->Select(state);
    anim->NextFrame();
}

void Judson::OnCollision(Object *other)
{
    if (other->Type() == ENEMY)
    {
        if (powered)
        {
            JudsonRun::panel->AddScore(100);
            JudsonRun::scene->Delete(other, MOVING);
        }
        else
        {
            // game over
        }
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
    shadow->Draw(float(int(x)), float(int(y) + 48), Layer::LOWER);
    anim->Draw(float(int(x)), float(int(y)), 0.9f - (y / float(window->Height())) * 0.8f);
}
