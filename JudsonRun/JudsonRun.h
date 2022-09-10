#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

#include "CppGenerator.h"
#include "Game.h"
#include "Scene.h"

enum JudsonRunObjects
{
    CPP,
    MOUSE,
    PLAYER,
    ENEMY,
};

class JudsonRun : public Game
{
  private:
    Sprite *bg = nullptr;
    Image *shadow = nullptr;

  public:
    static Scene *scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif
