#ifndef _HOME_H_
#define _HOME_H_

#include "Animation.h"
#include "Engine.h"
#include "JudsonRun.h"
#include "Object.h"

class Home : public Game
{
private:
    Sprite* bg2 = nullptr;

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif