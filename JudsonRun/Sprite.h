#ifndef _PROGJOGOS_SPRITE_H_
#define _PROGJOGOS_SPRITE_H_

#include "Image.h"
#include "Types.h"
#include <DirectXMath.h>
using namespace DirectX;

struct SpriteData
{
    float x, y;
    float scale;
    float depth;
    float rotation;
    uint  width;
    uint  height;
    ID3D11ShaderResourceView* texture;
    XMFLOAT2 texCoord;
    XMFLOAT2 texSize;
};

struct Layer
{
    static const float FRONT;
    static const float UPPER;
    static const float MIDDLE;
    static const float LOWER;
    static const float BACK;
};

class Sprite
{
private:
    SpriteData sprite;
    bool localImage;
    const Image * image;

public:
    Sprite(string filename);
    Sprite(const Image * img);
    ~Sprite();

    int Width();
    int Height();

    void Draw(float x, float y, float z = Layer::MIDDLE);
};

inline int Sprite::Width()
{ return image->Width(); }

inline int Sprite::Height()
{ return image->Height(); }

#endif
