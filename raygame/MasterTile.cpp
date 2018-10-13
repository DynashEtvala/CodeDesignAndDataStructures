#include "MasterTile.h"



MasterTile::MasterTile() : Tile()
{
	masterTile = true;
}

MasterTile::~MasterTile()
{}

void MasterTile::CycleTexture()
{
	currTex++;
	if (currTex >= 4)
	{
		currTex = 0;
	}
	Background = textures[currTex];
}