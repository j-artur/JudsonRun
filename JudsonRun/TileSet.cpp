#include "TileSet.h"
#include "Image.h"

TileSet::TileSet(string filename, uint tileWidth, uint tileHeight, uint numCols, uint numTiles) :
    image(new Image(filename)),
    width(tileWidth),
    height(tileHeight),
    columns(numCols),
    size(numTiles)
{
}

TileSet::~TileSet()
{
    if (image)
    {
         delete image;
    }
}
