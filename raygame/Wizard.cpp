#include "Wizard.h"



Wizard::Wizard(const std::string &fileName) : Player(fileName)
{}


Wizard::~Wizard()
{}

bool Wizard::moveTo(const Vector2 &dest)
{
	position = dest;
	return true;
}
