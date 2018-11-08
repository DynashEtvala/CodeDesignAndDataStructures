#include "FallingFactory.h"
#include <vector>

FallingFactory::FallingFactory()
{}


FallingFactory::~FallingFactory()
{
	delete spriteMasters;
}


void FallingFactory::operator=(FallingFactory const&)
{}

FallingFactory& FallingFactory::GetInstance()
{
	static FallingFactory instance;
	return instance;
}

void FallingFactory::init()
{
	//Load in the various sprites
	spriteCount = 4;
	spriteMasters = new SimpleSprite[spriteCount];
	spriteMasters[0] = SimpleSprite{ "Sprites/spaceMeteors_001.png", "rock", .1f };
	spriteMasters[1] = SimpleSprite{ "Sprites/spaceMeteors_002.png", "rock", .1f };
	spriteMasters[2] = SimpleSprite{ "Sprites/spaceMeteors_003.png", "rock", .1f };
	spriteMasters[3] = SimpleSprite{ "Sprites/spaceMeteors_004.png", "rock", .1f };
}

SimpleSprite* FallingFactory::getRandom()
{
	return &spriteMasters[rand() % spriteCount];
}

SimpleSprite* FallingFactory::getFromType(const std::string & _sprType)
{
	std::vector<SimpleSprite> hold;
	for (int i = 0; i < spriteCount; i++)
	{
		if (spriteMasters[i].sprType.compare(_sprType))
		{
			hold.push_back(spriteMasters[i]);
		}
	}
	return &hold[rand() % hold.size()];
}