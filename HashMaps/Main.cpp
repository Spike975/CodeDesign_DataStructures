#include "hash.h"

int main() {
	char * cString = new char[50];
	std::string news;
	std::cout << "Input words/leters:\n";
	std::cin.getline(cString, 6);
	std::cout << "Input words/leters:\n";
	std::cin >> news;

	std::cout << hashCString(cString, 5) << '\n';
	std::cout << hashStdString(news) << '\n';
	return 0;
}