#include "Sprite.h"

void Sprite::Draw()
{
	DrawTexture(spriteCells[0], x, y, WHITE);
}

Sprite::Sprite(const std::string *filename, const  int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; i++)
	{
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
	frameCount = cellCount;
	frameRate = _frameRate;
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{
	delete spriteCells;
}