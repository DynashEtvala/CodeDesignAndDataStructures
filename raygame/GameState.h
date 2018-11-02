#pragma once

enum GState { MainMenu = 0, PlayerSelect, InGame, GameOver };

class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	GState state;

public:
	static GState getState();
	static GState setState(GState newState);
	static GameState& GetInstance();
	~GameState();
};