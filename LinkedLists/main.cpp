#include "tLinkedList.h"

int main() {
	tForwardList<int> test;
	test.push_front(4);
	test.push_front(5);
	test.push_front(12);
	test.push_front(9);
	test.pop_front();
	test.pop_front();
	std::cout << test.front();
	return 0;
}