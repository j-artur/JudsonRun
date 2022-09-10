#include "Mouse.h"

Mouse::Mouse()
{
    type = MOUSE;

    BBox(new Point());
}

Mouse::~Mouse()
{
}

void Mouse::Update()
{
    MoveTo(float(window->MouseX()), float(window->MouseY()));
}

void Mouse::Draw()
{
}

void Mouse::OnCollision(Object *other)
{
    if (other->Type() != CPP)
        return;
    if (((Cpp *)other)->Falling())
        return;

    if (window->KeyDown(VK_LBUTTON))
    {
        if (!clickControl)
        {
            clickControl = true;
            JudsonRun::scene->Remove(other, MOVING);
        }
    }
    else
    {
        clickControl = false;
    }
}
