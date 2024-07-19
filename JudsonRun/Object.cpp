#include "Object.h"
#include "Engine.h"

Window* & Object::window   = Engine::window;
Game*   & Object::game     = Engine::game;
float   & Object::gameTime = Engine::frameTime;

Object::Object()
{
    posX = posY = 0.0f;

    posZ = 0.5f;

    type = 0;

    bbox = nullptr;
}

Object::~Object()
{
    if (bbox)
        delete bbox;
}

void Object::BBox(Geometry* bb)
{
    if (bbox)
        delete bbox;

    bbox = bb;
    bbox->Translate(x, y);
}

void Object::Translate(float dx, float dy, float dz)
{
    posX += dx;
    posY += dy;
    posZ += dz;

    if (bbox)
        bbox->Translate(dx, dy);
}

void Object::MoveTo(float px, float py, float pz)
{
    posX = px;
    posY = py;
    posZ = pz;

    if (bbox)
        bbox->MoveTo(px, py);
}

void Object::MoveTo(float px, float py)
{
    posX = px;
    posY = py;

    if (bbox)
        bbox->MoveTo(px, py);
}

void Object::OnCollision(Object* obj)
{
}
