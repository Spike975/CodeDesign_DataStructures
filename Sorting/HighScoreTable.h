#pragma once

#include "HighScoreEntry.h"
#include <string>
#include <fstream>
#include <vector>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	void bubbleSort();
	void insertSort();
	void bubbleSortRev();
	void insertSortRev();
	bool writeToDisk(std::string fileName);
	bool pruneBottomNNScores(int bottomRows);
	HighScoreTable();
	HighScoreTable(std::string fileName);
};