#ifndef _PLATFORMER_H_
#define _PLATFORMER_H_

#include "Cpp.h"
#include "CppGenerator.h"
#include "Engine.h"
#include "Game.h"
#include "Judson.h"
#include "Panel.h"
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
    static Panel *panel;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif
