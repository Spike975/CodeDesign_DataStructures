#include "functions.h"

void digitalPrinter() {
	int helpCount = 0;
	std::string fileName;
	std::string fileContents;
	std::ifstream file;
	std::cout << "Hello! What file do you want to read?\n";
	while (true) {
		std::cin >> fileName;

		file.open(fileName,std::ios::in);
		if (!file.fail()) {
			std::cout << "-----------------------\n";
			while (std::getline(file,fileContents)) {
				std::cout << fileContents + '\n';
			}
			std::cout << "\nWould you like to open another file?\n";
		}
		else {
			if (fileName == "no"|| fileName == "No") {
				break;
			}
			std::cout << "File doesn't exist.\n";
			helpCount++;
			if (helpCount >= 5) {
				std::cout << "Try adding a .txt to the end of the  file name,\nOr double check the spelling.\n";
			}
		}
		file.close();
	}
}
void myInfo() {
	std::string fileName;
	std::string input;
	std::ofstream file;
	std::cout << "Enter file name for data save:\n";
	std::cin >> fileName;
	file.open(fileName, std::ios::out);
	while (file.fail()) {
		std::cout << "This file can seem to be created(try adding .txt). Please enter again:\n";
		std::cin >> fileName;
	}
	std::cout << "\n\nEnter Name:\n";
	std::cin >> input;
	file << "Name: " << input << '\n';
	std::cin.clear();
	std::cout << "\n\nEnter Age:\n";
	std::cin >> input;
	file << "Age: " << input << '\n';
	std::cin.clear();
	std::cout << "\n\nEnter Favorite Color:\n";
	std::cin >> input;
	file << "Favorite Color: " << input << '\n';


	file.close();
}