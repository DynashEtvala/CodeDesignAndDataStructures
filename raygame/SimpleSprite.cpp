#include "SimpleSprite.h"

void SimpleSprite::translate(Vector2 delta)
{
	pos = Vector2{ pos.x + delta.x, pos.y + delta.y };
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r2, pos, rot, WHITE);
}

SimpleSprite::SimpleSprite()
{}


SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float scale)
{
	texture = LoadTexture(filename.c_str());
	r1 = Rectangle{ 0, 0, texture.width, texture.height };
	r2 = Rectangle{ 0, 0, r1.width * scale, r1.height * scale };
	sprType = _sprType;
	pos = Vector2{ 0, 0 };
	rot = 0;
}


SimpleSprite::~SimpleSprite()
{}
