#ifndef _PROGJOGOS_TILESET_H_
#define _PROGJOGOS_TILESET_H_

#include "Types.h"
#include "Image.h"
#include <string>
using std::string;

class TileSet
{
private:
    Image * image;
    uint width;
    uint height;
    uint columns;
    uint size;

public:
    TileSet(string filename,
            uint tileWidth,
            uint tileHeight,
            uint numCols,
            uint numTiles);
    ~TileSet();

    uint    TileWidth();
    uint    TileHeight();
    uint    Size();
    uint    Columns();
    uint    Width();
    uint    Height();

    ID3D11ShaderResourceView * View();
};

inline uint TileSet::TileWidth()
{ return width; }

inline uint TileSet::TileHeight()
{ return height; }

inline uint TileSet::Size()
{ return size; }

inline uint TileSet::Columns()
{ return columns; }

inline uint TileSet::Width()
{ return image->Width(); }

inline uint TileSet::Height()
{ return image->Height(); }

inline ID3D11ShaderResourceView * TileSet::View()
{ return image->View(); }

#endif
