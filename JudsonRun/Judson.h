#ifndef _JUDSON_H_
#define _JUDSON_H_

#include "Animation.h"
#include "Cpp.h"
#include "JudsonRun.h"
#include "Object.h"
#include "Panel.h"

enum WalkingState { STILLEFT, STILLRIGHT, WALKLEFT, WALKRIGHT, POWEREDLEFT, POWEREDRIGHT, POWEREDSTILLEFT, POWEREDSTILLRIGHT };
enum LastPressed { LEFT, RIGHT };

class Judson : public Object
{
  private:
    TileSet *tileSet = nullptr;
    Animation *anim = nullptr;
    Sprite *shadow = nullptr;
    float powered = false;
    float poweredTime = 0.0f;
    float speed = 400.0f;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    uint state = STILLRIGHT;
    uint lastPressed = RIGHT;

  public:
    Judson(Image *shadow);
    ~Judson();

    void OnCollision(Object *other);

    void Update();
    void Draw();
};

#endif
