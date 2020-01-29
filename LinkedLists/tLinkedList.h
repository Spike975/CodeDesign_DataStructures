#pragma once

#include <iostream>
#include <fstream>
#include <string>

template<typename K>
struct Node {
	K data;
	Node * next;
};

struct NodeB {
	int data;
	NodeB * next;
};

template<typename K>
class tForwardList {
	Node<K> * head;
	int size;
public:
	tForwardList() {
		head = NULL;
		size = 0;
	}
	tForwardList(const tForwardList & other) {
		head = other.head;
		size = other.size;
	}
	~tForwardList() {
		delete head;
	}
	tForwardList & operator= (const tForwardList &other) {
		head = other.head;
		size = other.size;
	}

	void print() {
		Node<K> * temp = head;
		Node<K> * temp2=NULL;
		while (temp != NULL){
			temp2 = temp;
			std::cout << temp2->data<< '\n';
			if (temp2->next == NULL) {
				break;
			}
			temp->data = temp2->next->data;
			temp->next = temp2->next->next;
		}
		delete temp;
		delete temp2;
	}
	void push_front(const K& val) {
		Node<K> * temp = new Node<K>;
		temp->data = val;
		temp->next = head;
		head = temp;
		size++;
	}
	void pop_front() {
		if (head != NULL) {
			head = head->next;
			size--;
		}
		else {
			std::cout << "No availible popout.";
		}
	}

	void clear() {
		head = NULL;
	}
	void resize(size_t newSize) {
		Node<K> * temp;
		if (newSize > size) {
			for (int i = size; i < newSize; i++) {
				temp = new Node<K>;
				temp->data = 0;
				temp->next = head;
				head = temp;
			}
		}
		else if(newSize == size){
			std::cout << "Same Size;";
		}
		else {
			for (int i = size; i < newSize; i++) {
				temp = new Node<K>;
				temp = head->next;
				head = temp;
			}
		}
		size = newSize;
	}
	void remove(const K & val) {
		Node<K> * temp = head, *prev=head;
		if (temp != NULL && temp->data == val) {
			head = temp->next;
			temp = head;
		}
		while (temp != NULL && temp->data != val){
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL) {
			return;
		}
		prev->next = temp->next;
		size--;
		remove(val);
		delete temp;
	}

	K& front() {
		return head[0].data;
	}
	const K& front() const {
		return head[0]->data;
	}

	bool empty() const {
		if (head == NULL) {
			return true;
		}
		return false;
	}
};

class iterator {
private:
	NodeB * current;

public:
	iterator() {
		current = new NodeB;
	}
	iterator(NodeB * startNode) {
		current = startNode;
	}

	bool operator==(const iterator & otherNode) const {
		if (&current == &otherNode.current) {
			return true;
		}
		return false;
	}
	bool operator!=(const iterator & otherNode) const {
		if (&current != &otherNode.current) {
			return true;
		}
		return false;
	}

};