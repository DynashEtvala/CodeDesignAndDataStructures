#pragma once

#include <iostream>
class HighScoreEntry
{
public:
	std::string name;
	int score;
	int level;

	HighScoreEntry() {};
	~HighScoreEntry() {};
};

bool operator==(HighScoreEntry a, HighScoreEntry b)
{
	return a.score == b.score;
}

bool operator<(HighScoreEntry a, HighScoreEntry b)
{
	return a.score < b.score;
}

bool operator>(HighScoreEntry a, HighScoreEntry b)
{
	return a.score > b.score;
}

bool operator<=(HighScoreEntry a, HighScoreEntry b)
{
	return a.score <= b.score;
}

bool operator>=(HighScoreEntry a, HighScoreEntry b)
{
	return a.score <= b.score;
}