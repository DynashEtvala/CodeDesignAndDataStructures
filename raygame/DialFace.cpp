#include "DialFace.h"


void DialFace::DrawFace()
{
	DrawCircleLines(position.x, position.y, radius, BLACK);
	DrawLineV(position, Vector2{ ((float)(sin(currentAngle * PI)) * radius) + position.x, ((float)(cos((1 - currentAngle) * PI)) * radius) + position.y }, BLUE);
}

void DialFace::Tick()
{

}

DialFace::DialFace()
{
	
}


DialFace::~DialFace()
{}
