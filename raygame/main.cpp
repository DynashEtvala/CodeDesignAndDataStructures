/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "MasterTile.h"
#include "EvilEnt.h"
#include "Necromancer.h"
#include "Button.h"
#include "DialFace.h"
#include <vector>
#include <iterator>

typedef DialFace Clock;

Vector2 Clock::position = Vector2{ 100, 100 };
float Clock::radius = 75;
float Clock::currentAngle = 0;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 640;
	int screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Tile tileList[10][10];

	tileList[0][0] = MasterTile{};

	std::vector<Enemy*> enemies;

	int countN = 0;
	int countE = 0;

	bool play = false;

	Button addN;
	Button remN;
	Button addE;
	Button remE;
	Button playB;

	Clock clock;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		Clock::currentAngle += GetFrameTime() / 30;
		if (Clock::currentAngle >= 2)
		{
			Clock::currentAngle -= 2;
		}

		if (play)
		{
			for (auto enem = enemies.begin(); enem != enemies.end(); enem++)
			{
				(*enem)->Update();
			}
		}
		else
		{
			if (addN.CheckForClick())
			{
				countN++;
			}
			if (remN.CheckForClick() && countN != 0)
			{
				countN--;
			}
			if (addE.CheckForClick())
			{
				countN++;
			}
			if (remE.CheckForClick())
			{
				countN++;
			}
			if (playB.CheckForClick())
			{
				for (int i = 0; i < countE; i++)
				{
					enemies.push_back(new EvilEnt{});
				}
				for (int i = 0; i < countE; i++)
				{
					enemies.push_back(new Necromancer{});
				}
				play = true;
			}
		}

		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			tileList[0][0].CycleTexture();
		}

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				DrawTexture(tileList[i][j].Background, j * 64, i * 64, tileList[i][j].tint);
			}
		}

		clock.DrawFace();

		DrawRectangleLines(0, 0, 64, 64, RED);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}