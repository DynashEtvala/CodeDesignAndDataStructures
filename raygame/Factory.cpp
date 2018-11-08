#include "Factory.h"



Factory::Factory()
{}


Factory::~Factory()
{}


void Factory::operator=(Factory const&) 
{}

Factory& Factory::GetInstance()
{
	static Factory instance;
	return instance;
}

IBox* Factory::Create(std::string type)
{
	if (type == "Red")
		return new RedBox();

	if (type == "Blue")
		return new BlueBox();

	return NULL;
}