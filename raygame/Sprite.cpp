#include "Sprite.h"

void Sprite::Draw()
{
	DrawTexture(spriteCells[0], x, y, WHITE);
}

Sprite::Sprite(const std::string *filename, const  int cellCount = 1, const float _frameRate = 25.0)
{
	spriteCells[0] = LoadTexture(filename->c_str);
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