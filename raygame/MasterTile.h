#pragma once
#include "Tile.h"
class MasterTile :
	public Tile
{
public:
	Texture2D textures[4];
	int currTex = 0;
	MasterTile();
	~MasterTile();
	void CycleTexture();
};

