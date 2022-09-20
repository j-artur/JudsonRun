#ifndef _PANEL_H_
#define _PANEL_H_

#include "Animation.h"
#include "Object.h"
#include <iomanip>
#include <sstream>
#include <string>
using std::setfill;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;

class Panel : public Object
{
  private:
    Sprite *background = nullptr;
    TileSet *numbers = nullptr;
    Animation *anim = nullptr;
    float time = 0.0f;
    uint score = 0;
    string scoreTxt = "000000000";

  public:
    Panel();
    ~Panel();

    void AddScore(uint s);
    uint Score();

    void Update();
    void Draw();
};

#endif
