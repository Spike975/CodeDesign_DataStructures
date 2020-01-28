#pragma once

#include <iostream>
#include <fstream>
#include <string>

template<typename T>
struct Node {
	T data;
	Node * next;
};

struct NodeB {
	int data;
	NodeB * next;
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
		Node<T> * temp = head;
		Node<T> * temp2=NULL;
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
	void push_front(const T& val) {
		Node<T> * temp = new Node<T>;
		temp->data = val;
		temp->next = head;
		head = temp;
		size++;
	}
	void pop_front() {
		if (head != NULL) {
			Node<T> * temp = new Node<T>;
			temp = head->next;
			head = temp;
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
		Node<T> * temp;
		if (newSize > size) {
			for (int i = size; i < newSize; i++) {
				temp = new Node<T>;
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
				temp = new Node<T>;
				temp = head->next;
				head = temp;
			}
		}
		size = newSize;
	}
	void remove(const T & val) {
		Node<T> * temp = head, *prev=head;
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