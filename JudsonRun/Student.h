#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Animation.h"
#include "JudsonRun.h"
#include "Object.h"

enum WalkingDirection
{
    WLEFT,
    WRIGHT
};

enum StudentsType
{
    ABRAAO,
    WILLIAM,
    ARTUR,
    GUILHERM
};

class Student : public Object
{
  private:
    Animation *anim = nullptr;
    Sprite *shadow = nullptr;
    uint walkingDirection = WLEFT;
    float speed;

  public:
    Student(TileSet *tileset, Image *shadow, int x, int y, uint direction, StudentsType type);
    ~Student();

    void Update();
    void Draw();
};

#endif
