#include "tVector.h"
#include "Stack.h"
int main() {
	tVector<int> * test = new tVector<int>;
	tStack<int> tests;
	tQueue<int> queue;

	queue.push(14);
	queue.print();
	queue.push(11);
	queue.print();
	queue.push(7);
	queue.print();
	queue.push(9);
	queue.print();
	queue.pop();
	queue.print();
	return 0;
}