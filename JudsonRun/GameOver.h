#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "Animation.h"
#include "Engine.h"
#include "JudsonRun.h"
#include "Object.h"

class GameOver : public Game
{
  private:
    Sprite *bg = nullptr;

  public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

#endif
