#include "Barbarian.h"
#include <math.h>


Barbarian::Barbarian(const std::string &fileName) : Player(fileName)
{
	speed = 30;
}


Barbarian::~Barbarian()
{}


bool Barbarian::moveTo(const Vector2 &dest)
{
	Vector2 v = { GetMousePosition().x - position.x, GetMousePosition().y - position.y };
	if (v.x != 0 && v.y != 0)
	{
		float l = sqrt((v.x * v.x) + (v.y * v.y));
		v.x = v.x / l;
		v.y = v.y / l;
	}
	else if (v.x != 0)
	{
		if (v.x > 0)
		{
			v.x = 1;
		}
		else
		{
			v.x = -1;
		}
	}
	else if (v.y != 0)
	{
		if (v.y > 0)
		{
			v.y = 1;
		}
		else
		{
			v.y = -1;
		}
	}
	position.x += v.x * speed;
	position.y += v.y * speed;
	if (position.x == GetMousePosition().x && position.y == GetMousePosition().y)
	{
		return true;
	}
	return false;
}