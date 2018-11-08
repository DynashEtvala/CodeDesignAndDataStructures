#pragma once
#include "IBox.h"
class RedBox :
	public IBox
{
public:
	std::string Color(void);

	RedBox();
	~RedBox();
};

