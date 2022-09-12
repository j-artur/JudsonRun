#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Animation.h"
#include "JudsonRun.h"
#include "Object.h"

enum WalkingDirection { WLEFT, WRIGHT };

class Student : public Object
{
private:
    Animation* anim = nullptr;
    Sprite* shadow = nullptr;
    uint walkingDirection = WLEFT;
    float speed;

public:
    Student(TileSet* tileset, Image* shadow, int x, int y);
    ~Student();


    void Update();
    void Draw();
};

#endif
