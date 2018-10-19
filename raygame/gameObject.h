#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	void update(float delta)
	{
		if (enabled)
		object.update();
	}

	void render()
	{
		if (enabled)
		object.render();
	}

	// todo: What else would you need to include in this class declaration?
};