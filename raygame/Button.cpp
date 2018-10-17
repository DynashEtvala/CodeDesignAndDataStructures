#include "Button.h"


void Button::Draw() 
{
	if (CheckForClick())
	{
		DrawTexture(spriteCells[1], x, y, WHITE);
	}
	else
	{
		DrawTexture(spriteCells[0], x, y, WHITE);
	}
}

bool Button::CheckForClick()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), Rectangle {x, y, spriteCells[0].width, spriteCells[0].height}))
	{
		return true;
	}
	return false;
}

Button::Button(const std::string *filename, const Vector2 & position, const  int cellCount = 1) : Sprite(filename, cellCount, 25.0f)
{
	x = position.x;
	y = position.y;
}

Button::Button()
{

}

Button::~Button()
{

}
