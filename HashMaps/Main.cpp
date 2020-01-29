#include "hash.h"

int main() {
	std::string key = "test";
	tHashmap<std::string, int> * test = new tHashmap<std::string, int>(50);

	test->setKey(key, 5);
	
	std::cout << test[key];

	return 0;
}