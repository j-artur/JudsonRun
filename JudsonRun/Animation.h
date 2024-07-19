#ifndef _PROGJOGOS_ANIMATION_H_
#define _PROGJOGOS_ANIMATION_H_

#include "Sprite.h"
#include "TileSet.h"
#include "Timer.h"
#include "Types.h"

#include <unordered_map>
using std::unordered_map;
using std::pair;

using AnimSeq = pair<uint*, uint>;

using HashTable = unordered_map<uint, AnimSeq>;

class Animation
{
private:
    uint  iniFrame;
    uint  endFrame;
    uint  frame;
    bool  animLoop;
    float animDelay;
    Timer timer;
    TileSet * tileSet;
    SpriteData sprite;
    HashTable table;
    uint * sequence;

public:
    Animation(TileSet* tiles, float delay, bool repeat);
    ~Animation();

    void Add(uint id, uint * seq, uint seqSize);

    void Select(uint id);

    void Draw(float x, float y, float z = Layer::MIDDLE);

    void Draw(uint aFrame, float x, float y, float z = Layer::MIDDLE);

    void Frame(uint aFrame);
    uint Frame();
    bool Inactive();
    void NextFrame();
    void Restart();
};

inline void Animation::Draw(float x, float y, float z)
{ sequence ? Draw(sequence[frame], x, y, z) : Draw(frame, x, y, z); }

inline void Animation::Frame(uint aFrame)
{ frame = aFrame; }

inline unsigned Animation::Frame()
{ return (sequence ? sequence[frame] : frame); }

inline bool Animation::Inactive()
{ return !animLoop && (frame > endFrame || (frame == endFrame && timer.Elapsed(animDelay))); }

inline void Animation::Restart()
{ frame = 0; timer.Start(); }

#endif
