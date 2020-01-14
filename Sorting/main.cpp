#include "HighScoreTable.h"

int main() {

	HighScoreTable hst("highscores.txt");

	std::cout << "\n";
	
	hst.insertSort();
	hst.insertSortRev();
	hst.bubbleSort();
	hst.bubbleSortRev();

	if (hst.writeToDisk("highscores.txt")) {
		std::cout << "Sucessfuly wrote to disk.";
	}
	else {
		std::cout << "Something broke.";
	}

	return 0;
}