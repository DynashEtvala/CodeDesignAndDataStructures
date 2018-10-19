#pragma once
#include "Player.h"
class Barbarian :
	public Player
{
public:
	Barbarian(const std::string &fileName);
	~Barbarian();
	bool moveTo(const Vector2 &dest);
};

