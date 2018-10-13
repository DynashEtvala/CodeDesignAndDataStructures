#include "Tile.h"
#include "MasterTile.h"

Tile::Tile(std::string imageFilename)
{
	Background = LoadTexture(imageFilename.c_str());
}

Tile::Tile()
{
	Background = LoadTexture("resources\\mappack\\PNG\\mapTile_188.png");
}

Tile::~Tile()
{

}

void Tile::operator=(MasterTile a)
{
	Background = a.Background;
	tint = a.tint;
}