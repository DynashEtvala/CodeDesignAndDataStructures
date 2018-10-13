#pragma once
#include <string>
#include <iostream>
#include "raylib.h"
class Tile
{
public:
	bool masterTile;
	Texture2D Background;
	Color tint = WHITE;
	Tile(std::string imageFilename);
	Tile();
	~Tile();
	void operator=(class MasterTile a);
	virtual void CycleTexture() {};
};