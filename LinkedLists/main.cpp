#include "tLinkedList.h"

int main() {
	tForwardList<int> * test = new tForwardList<int>;
	test->push_front(4);
	test->push_front(5);
	test->push_front(12);
	test->push_front(9);
	test->pop_front();

	test->resize(6);

	tForwardList<int> * newList = test;

	newList->print();
	return 0;
}