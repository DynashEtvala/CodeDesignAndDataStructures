#pragma once
#include "raylib.h"
#include "SimpleSprite.h"

class FallingFactory
{
private:
	FallingFactory();
	FallingFactory(FallingFactory const&);
	void operator=(FallingFactory const&);
	SimpleSprite* spriteMasters;
	size_t spriteCount;

public:
	static FallingFactory& GetInstance();

	void init();

	SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

	~FallingFactory();
};

