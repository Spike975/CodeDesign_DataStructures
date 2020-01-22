#include "tVector.h"
int main() {
	tVector<int> * test = new tVector<int>;

	test->push_back(14);
	test->push_back(18);
	test->push_back(8);
	test->push_back(3);
	test->push_back(5);
	test->pop_back();
	test->reserve(10);

	test->print();

	return 0;
}