#pragma once

#include <iostream>
#include <fstream>
#include <string>

template<typename T>
struct Node {
	T data;
	Node * next;
};

template<typename T>
class tForwardList {
	Node<T> * head;
	int size;
public:
	tForwardList() {
		head = NULL;
		size = 0;
	}
	~tForwardList() {
		delete head;
	}
	tForwardList(const tForwardList & other) {
		head = other.head;
		size = other.size;
	}
	tForwardList & operator= (const tForwardList &other) {
		head = other.head;
		size = other.size;
	}

	void print() {
		Node<T> * temp = head;
		Node<T> * temp2;
		for (int i = 0; i < size; i++) {
			temp2 = temp;
			std::cout << temp2->data<< '\n';
			if (temp2->next == NULL) {
				break;
			}
			temp->data = temp2->next->data;
			temp->next = temp2->next->next;
		}
	}
	void push_front(const T& val) {
		Node<T> * temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		size++;
	}
	void pop_front() {
		if (head != NULL) {
			Node<T> * temp = new Node;
			temp = head->next;
			head = temp;
		}
		else {
			std::cout << "No availible popout.";
		}
		size--;
	}
	void remove(const T& val) {
		Node<T> * temp;
		temp = head;
		while(true){
			if (temp->data == val) {
				std::cout << "TESTING";
			}
			else {
				std::cout << "TESTING";
			}
		}
		delete temp;
	}
	void clear() {
		head = NULL;
	}
	void resize(size_t newSize) {
		Node * temp;
		if (newSize > size) {
			for (int i = size; i < newSize; i++) {
				temp = new Node;
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
				temp = new Node;
				temp->data = head->next->data;
				temp->next = head->next->next;
				head = temp;
			}
		}
		size = newSize;
	}

	T& front() {
		return head[0].data;
	}
	const T& front() const {
		return head[0]->data;
	}

	bool empty() const {
		if (head == NULL) {
			return true;
		}
		return false;
	}
};

template<typename T>
class interator {
private:
	Node<T> * current;

public:
	interator() {
		current = new Node<T>;
	}
	interator(Node<T> * startNode) {
		current = startNode;
	}

	bool operator==(const iterator<T> & otherNode) const {
		if (&current == &otherNode) {
			return true;
		}
		return false;
	}
	bool operator!=(const iterator<T> & otherNode) const {

	}

};