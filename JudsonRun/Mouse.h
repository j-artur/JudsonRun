#ifndef _MOUSE_H_
#define _MOUSE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "JudsonRun.h"
#include "Object.h"

// ------------------------------------------------------------------------------

class Mouse : public Object
{
  private:
    bool clickControl = false;

  public:
    Mouse();
    ~Mouse();

    void Update();
    void Draw();

    void OnCollision(Object *other);
};

// ---------------------------------------------------------------------------------

#endif
