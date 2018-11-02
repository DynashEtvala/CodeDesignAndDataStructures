#include "HighScoreTable.h"
#include <fstream>
#include <iostream>
#include <string>

using std::vector;
using std::fstream;

vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	vector<HighScoreEntry> result;

	for (int i = 0; i < topRows; i++)
	{
		result.push_back(HighScoreEntry{});
		result.at(i) = hsVector.at(i);
	}

	return result;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	if (bottomRows > hsVector.size())
	{
		return false;
	}
	for (int i = 0; i < bottomRows; i++)
	{
		hsVector.pop_back();
	}
	return true;
}



HighScoreTable::HighScoreTable()
{

}	

HighScoreTable::HighScoreTable(std::string fileName)
{
	fstream file;
	file.open(fileName.c_str(), std::ios::out);
	std::string buffer;
	while (getline(file, buffer))
	{
		hsVector.push_back(HighScoreEntry{});
		std::string delimiter = ",";

		size_t pos = 0;
		vector<std::string> tokens;
		int i = 0;
		while ((pos = buffer.find(delimiter)) != std::string::npos)
		{
			tokens[i] = buffer.substr(0, pos);
			buffer.erase(0, pos + delimiter.length());
		}
		hsVector.back().name = tokens[0];
		hsVector.back().score = atoi(tokens[1].c_str());
		hsVector.back().level = atoi(tokens[2].c_str());
	}
	for (int i = 0; i < hsVector.size() - 1; i++)
	{
		for (int j = i + 1; j < hsVector.size(); j++)
		{
			if (hsVector[j].score < hsVector[i].score)
			{
				HighScoreEntry hold = hsVector[i];
				hsVector[i] = hsVector[j];
				hsVector[j] = hold;
				break;
			}
		}
	}
}

HighScoreTable::HighScoreTable(std::string fileName, bool insertion)
{
	fstream file;
	file.open(fileName.c_str(), std::ios::out);
	std::string buffer;
	while (getline(file, buffer))
	{
		hsVector.push_back(HighScoreEntry{});
		std::string delimiter = ",";

		size_t pos = 0;
		vector<std::string> tokens;
		int i = 0;
		while ((pos = buffer.find(delimiter)) != std::string::npos)
		{
			tokens[i] = buffer.substr(0, pos);
			buffer.erase(0, pos + delimiter.length());
		}
		hsVector.back().name = tokens[0];
		hsVector.back().score = atoi(tokens[1].c_str());
		hsVector.back().level = atoi(tokens[2].c_str());
	}
	for (int i = 0; i < hsVector.size; i++)
	{
		for (int j = i; j > 0 && hsVector[j - 1].score > hsVector[j].score; j--)
		{
			HighScoreEntry hold = hsVector[j - 1];
			hsVector[j - 1] = hsVector[j];
			hsVector[j] = hold;
		}
	}
}
	
HighScoreTable::~HighScoreTable()
{

}