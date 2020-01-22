#pragma once

#include <iostream>
#include <fstream>
#include <string>

template<typename T>
class tForwardList {
	struct Node {
		T data;
		Node * next;
	};
	Node * head;
public:
	tForwardList() {
		head = NULL;
	}
	~tForwardList() {
		delete head;
	}

	void push_front(const T& val) {
		if (head == NULL) {
			head = new Node;
			head->next = NULL;
		}
		else {
			head->next = head;
		}
		head->data = val;
	}
	void pop_front() {
		if (head != NULL) {
			head = head->next;
		}
		else {
			std::cout << "No availible popout.";
		}
	}

	T& front() {
		return head[0].data;
	}
	const T& front() const {
		return head[0].data;
	}

	void remove(const T& val) {
		Node * temp;
		temp = head;
		while(true){
			if (temp.data == val) {
				std::cout << "TESTING";
			}
			else {
				std::cout << "TESTING";
			}
		}
		delete temp;
	}
};