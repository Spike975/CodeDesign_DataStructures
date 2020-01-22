#include "Singleton.h"

int main() {
	TestSingleton * test = new TestSingleton;
	std::string input;

	std::cout << "This is a test of a game...\n\n\n";
	while (true) {
		if (test->getState()==0) {
			std::cout << "Main Menu:\n";
			std::cout << "[1]  START\n[2]  Quit\n";
			std::cin >> input;
			if (input == "1") {
				test->setState(Begining);
			}
			else if (input == "2") {
				test->setState(End);
			}
		}
		else if (test->getState() == 1) {
			std::cout << "GAME:\n";
			std::cout << "[1]  GO\n[2]  BACK\n";
			std::cin >> input;
			if (input == "1") {
				test->setState(Quest);
			}
			else if (input == "2") {
				test->setState(MainMenu);
			}
		}
		else if (test->getState() == 2) {
			std::cout << "Adventure:\n";
			std::cout << "[1]  GO\n[2]  BACK\n";
			std::cin >> input;
			if (input == "1") {
				test->setState(Final);
			}
			else if (input == "2") {
				test->setState(Begining);
			}
		}
		else if (test->getState() == 3) {
			std::cout << "END:\n";
			std::cout << "[1]  END\n[2]  BACK\n";
			std::cin >> input;
			if (input == "1") {
				test->setState(End);
			}
			else if (input == "2") {
				test->setState(Quest);
			}
		}
		else if (test->getState() == 4) {
			std::cout << "Game Done";
			break;
		}
	}

	return 0;
}