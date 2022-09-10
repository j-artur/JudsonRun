#ifndef _CPP_H_
#define _CPP_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"
#include "JudsonRun.h"
#include "Object.h"

// ------------------------------------------------------------------------------

class Cpp : public Object
{
  private:
    Animation *anim = nullptr;
    Sprite *shadow = nullptr;
    int targetY;
    bool falling = true;
    float timer = 0.0f;

  public:
    Cpp(TileSet *tileset, Image *shadow, int x, int targetY);
    ~Cpp();

    bool Falling() const
    {
        return falling;
    }

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif
