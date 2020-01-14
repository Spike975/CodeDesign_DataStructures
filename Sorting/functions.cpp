#include "HighScoreTable.h"


HighScoreTable::HighScoreTable() {
	for (int i = 0; i < 10; i++) {
		hsVector[i].name = "";
		hsVector[i].score = 0;
		hsVector[i].level = 0;
	}
}
HighScoreTable::HighScoreTable(std::string fileName) {
	int players = 0;
	std::ifstream file;
	file.open(fileName, std::ios::in);
	while (true) {
		std::string player;
		HighScoreEntry entry;
		if (!std::getline(file, player)) {
			break;
		}
		int col = 0;
		std::string temp;
		for (int x = 0; x < player.length(); x++) {
			if (player[x] != ',' && x != player.length()-1) {
				temp += player[x];
			}
			else{
				col++;
				if (col == 1) {
					entry.name = temp;
				}
				else if (col == 2) {
					entry.score = std::stoi(temp);
				}
				else {
					temp += player[x];
					entry.level = std::stoi(temp);
					col = 0;
					break;
				}
				temp = "";
			}
		}
		hsVector.push_back(entry);
	}
	file.close();
}
bool HighScoreTable::pruneBottomNNScores(int bottomRows) {
	if (hsVector.size() > bottomRows) {
		for (int i = 0; i < bottomRows; i++) {
			hsVector.pop_back();
		}
		return true;
	}
	else {
		return false;
	}
}
std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows) {
	//bubbleSort();
	bubbleSortRev();
	//insertSort;
	//insertSortRev;
	if (topRows > hsVector.size()) {
		topRows = (int)hsVector.size();
	}
	std::vector<HighScoreEntry> scores;
	for (size_t i = 0; i < topRows; i++) {
		scores.push_back(hsVector[i]);
	}
	return scores;
}
void HighScoreTable::bubbleSort() {
	HighScoreEntry temp;
	for (size_t i = hsVector.size() - 1; i >= 0; i--) {
		int changes = 0;
		for (int x = 0; x < i;x++) {

			if (hsVector[x].score < hsVector[x+1].score) {
				temp = hsVector[x];
				hsVector[x] = hsVector[x+1];
				hsVector[x + 1] = temp;
				changes++;
			}
		}
		if (changes == 0) {
				break;
		}
		changes = 0;
	}
}
void HighScoreTable::insertSort() {
	HighScoreEntry temp;
	for (int i = 1; i < hsVector.size(); i++) {
		for (int x = i; x > 0; x --) {
			if(hsVector[x].score > hsVector[x-1].score){
				temp = hsVector[x];
				hsVector[x] = hsVector[x - 1];
				hsVector[x-1] = temp;
			}
			else {
				break;
			}
		}
	}
}
void HighScoreTable::bubbleSortRev() {
	HighScoreEntry temp;
	for (size_t i = hsVector.size() - 1; i >= 0; i--) {
		int changes = 0;
		for (int x = 0; x < i; x++) {

			if (hsVector[x].score > hsVector[x + 1].score) {
				temp = hsVector[x];
				hsVector[x] = hsVector[x + 1];
				hsVector[x + 1] = temp;
				changes++;
			}
		}
		if (changes == 0) {
			break;
		}
		changes = 0;
	}
}
void HighScoreTable::insertSortRev() {
	HighScoreEntry temp;
	for (int i = 1; i < hsVector.size(); i++) {
		for (int x = i; x > 0; x--) {
			if (hsVector[x].score < hsVector[x - 1].score) {
				temp = hsVector[x];
				hsVector[x] = hsVector[x - 1];
				hsVector[x - 1] = temp;
			}
			else {
				break;
			}
		}
	}
}
bool HighScoreTable::writeToDisk(std::string fileName) {
	std::ofstream file;
	file.open(fileName, std::ios::out);
	if (file.fail()) {
		std::cout << "No file at specified path\n";
		return false;
	}
	for (size_t i = 0; i < hsVector.size(); i++) {
		file << hsVector[i].name << "," << hsVector[i].score << "," << hsVector[i].level << "\n";
	}

	file.close();
	return true;
}