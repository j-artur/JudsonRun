#ifndef _PROGJOGOS_TIMER_H_
#define _PROGJOGOS_TIMER_H_

#include <windows.h>

class Timer
{
private:
    LARGE_INTEGER start, end;
    LARGE_INTEGER freq;
    bool stoped;

public:
    Timer();

    void  Start();
    void  Stop();
    float Reset();
    float Elapsed();
    bool  Elapsed(float secs);
};

inline bool Timer::Elapsed(float secs)
{ return (Elapsed() >= secs ? true : false); }

#endif
