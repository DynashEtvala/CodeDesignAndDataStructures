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
#include "GameState.h"
#include <deque>
#include <iterator>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 500;
	int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	float blockSpeed = 250.0f;
	float blockTimer = 0;
	float blockSize = 100;

	std::deque<Rectangle> blocks;
	blocks.resize(1);

	int colornumber = 0;

	float playerSize = (75.0f) / 2;
	Color playerColor = RED;
	int playerColumn = 2;

	float scoreTime = 0;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		
		switch (GameState::getState())
		{
		default:
		case MainMenu:
			if (IsKeyReleased(KEY_ENTER))
			{
				GameState::setState(PlayerSelect);
			}
			break;
		case PlayerSelect:
			if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT))
			{
				switch (colornumber)
				{
				default:
				case 0:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = PURPLE;
						colornumber = 5;
					}
					else
					{
						playerColor = ORANGE;
						colornumber++;
					}
					break;
				case 1:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = RED;
						colornumber--;
					}
					else
					{
						playerColor = YELLOW;
						colornumber++;
					}
					break;
				case 2:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = ORANGE;
						colornumber--;
					}
					else
					{
						playerColor = GREEN;
						colornumber++;
					}
					break;
				case 3:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = YELLOW;
						colornumber--;
					}
					else
					{
						playerColor = BLUE;
						colornumber++;
					}
					break;
				case 4:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = GREEN;
						colornumber--;
					}
					else
					{
						playerColor = PURPLE;
						colornumber++;
					}
					break;
				case 5:
					if (IsKeyPressed(KEY_LEFT))
					{
						playerColor = BLUE;
						colornumber--;
					}
					else
					{
						playerColor = RED;
						colornumber = 0;
					}
					break;
				}
			}
			if (IsKeyReleased(KEY_ENTER))
			{
				GameState::setState(InGame);
			}
			break;
		case InGame:
			blockTimer += blockSpeed * GetFrameTime();
			if (blockTimer >= blockSize * 2)
			{
				blocks.push_back(Rectangle{ (rand() % 5)*blockSize, -blockSize, blockSize, blockSize });
				blockTimer -= blockSize * 2;
			}
			if (blocks[0].y > screenHeight)
			{
				blocks.pop_front();
				blockSpeed += blockSpeed * 0.01;
			}
			if (IsKeyPressed(KEY_LEFT) && playerColumn != 0)
			{
				playerColumn--;
			}
			else if (IsKeyPressed(KEY_RIGHT) && playerColumn != 4)
			{
				playerColumn++;
			}
			for (auto iter = blocks.begin(); iter != blocks.end(); iter++)
			{
				iter->y += blockSpeed * GetFrameTime();
				if (CheckCollisionCircleRec(Vector2{ (float)(playerColumn * 100 + 50), (float)(screenHeight - 150) }, playerSize, Rectangle{ iter->x, iter->y, iter->width, iter->height }))
				{
					GameState::setState(GameOver);
					break;
				}
			}
			scoreTime += GetFrameTime();
			break;
		case GameOver:
			if (IsKeyReleased(KEY_ENTER))
			{
				blockSpeed = 250.0f;
				blockTimer = 0;

				while (blocks.size() != 0)
				{
					blocks.pop_back();
				}
				blocks.resize(1);

				playerColumn = 2;

				scoreTime = 0;
				GameState::setState(MainMenu);
			}
			break;
		}

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(WHITE);

		switch (GameState::getState())
		{
		default:
		case MainMenu:
			DrawText("PRESS ENTER TO BEGIN", 50, 700, 30, Color{ 0, 0, 0, (unsigned char)(((int)GetTime() % 2) * 255) });
			break;
		case PlayerSelect:
			DrawTriangle(Vector2{ (float)(playerColumn * 100 - 10), (float)(screenHeight - 150) }, Vector2{ (float)(playerColumn * 100 + 10), (float)(screenHeight - 130) }, Vector2{ (float)(playerColumn * 100 + 10), (float)(screenHeight - 170) }, BLACK);
			DrawTriangle(Vector2{ (float)((playerColumn + 1) * 100 + 9), (float)(screenHeight - 150) }, Vector2{ (float)((playerColumn + 1) * 100 - 11), (float)(screenHeight - 170) }, Vector2{ (float)((playerColumn + 1) * 100 - 11), (float)(screenHeight - 130) }, BLACK);
		case InGame:
			DrawCircle(playerColumn * 100 + 50, screenHeight - 150, playerSize, BLACK);
			DrawCircle(playerColumn * 100 + 50, screenHeight - 150, playerSize - 1, playerColor);
			for (auto iter = blocks.begin(); iter != blocks.end(); iter++)
			{
				DrawRectangleRec(Rectangle{iter->x, iter->y, iter->width, iter->height}, BLACK);
			}
			DrawText(std::to_string(scoreTime).c_str(), 183, 950, 30, Color{ 0, 0, 0, (unsigned char)255 });
			break;
		case GameOver:
			DrawCircle(playerColumn * 100 + 50, screenHeight - 150, playerSize, BLACK);
			DrawCircle(playerColumn * 100 + 50, screenHeight - 150, playerSize - 1, playerColor);
			for (auto iter = blocks.begin(); iter != blocks.end(); iter++)
			{
				DrawRectangleRec(Rectangle{ iter->x, iter->y, iter->width, iter->height }, BLACK);
			}
			DrawRectangle(0, 0, screenWidth, screenHeight, { (unsigned char)255, (unsigned char)255, (unsigned char)255, (unsigned char)127 });
			DrawText("YOUR TIME:", 168, 300, 30, Color{ 0, 0, 0, (unsigned char)255 });
			DrawText(std::to_string(scoreTime).c_str(), 183, 350, 30, Color{ 0, 0, 0, (unsigned char)255 });
			DrawText("PRESS ENTER TO RESTART", 35, 750, 30, Color{ 0, 0, 0, (unsigned char)(((int)GetTime() % 2) * 255) });
			break;
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}