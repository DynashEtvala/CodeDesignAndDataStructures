#pragma once

#include "HighScoreEntry.h"
#include <vector>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreEntry operator[](size_t i) { return hsVector[i]; };

	HighScoreTable();
	HighScoreTable(std::string fileName);
	HighScoreTable(std::string fileName, bool insertion);
	~HighScoreTable();
};