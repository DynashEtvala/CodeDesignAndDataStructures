#include "Player.h"

Player::Player(const std::string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

Player::~Player()
{

}

bool Player::moveTo(const Vector2 &dest)
{
	return false;
}

void Player::draw()
{
	DrawCircle(position.x, position.y, 20, WHITE);
}