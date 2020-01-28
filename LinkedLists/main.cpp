#include "tLinkedList.h"

int main() {
	tForwardList<int> * test = new tForwardList<int>;
	test->push_front(5);
	test->push_front(7);
	test->push_front(2);
	test->push_front(12);
	test->push_front(9);
	test->pop_front();

	test->resize(6);

	test->remove(0);

	test->print();
	return 0;
}