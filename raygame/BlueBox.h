#pragma once
#include "IBox.h"
class BlueBox :
	public IBox
{
public:
	BlueBox();
	~BlueBox();
	std::string Color(void);
};

