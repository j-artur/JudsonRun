#ifndef _JUDSON_H_
#define _JUDSON_H_

#include "Animation.h"
#include "JudsonRun.h"
#include "Object.h"

class Judson : public Object
{
  private:
    TileSet *tileSet = nullptr;
    Animation *anim = nullptr;
    Sprite *shadow = nullptr;
    float powered = false;
    float poweredTime = 0.0f;
    float speed;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;

  public:
    Judson(Image *shadow);
    ~Judson();

    void OnCollision(Object *other);

    void Update();
    void Draw();
};

#endif
