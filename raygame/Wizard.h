#pragma once
#include "Player.h"
class Wizard :
	public Player
{
public:
	Wizard(const std::string &fileName);
	~Wizard();
	bool moveTo(const Vector2 &dest);
};

