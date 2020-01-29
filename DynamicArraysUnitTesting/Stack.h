#pragma once

template <typename K>
class tStack{
private:
	tVector<K> * vec;
public:
	tStack() {
		vec = new tVector<K>;
	}
	K & operator[](size_t index) {
		return vec.at(index);
	}

	void push(const K & value) {
		vec->push_front(value);
	}
	void pop() {
		vec->pop_front();
	}

	K & top() {
		return vec[0];
	}

	size_t size() const {
		return vec->size();
	}
	bool empty() const {
		return vec->empty();
	}
};


template <typename K>
class tQueue{
private:
	tVector<K> * vec;
public:
	tQueue() {
		vec = new tVector<K>;
	}
	tQueue(size_t count, const K & value) {
		vec = new tVector<K>;
		for (int i = 0; i < count; i++) {
			push(value);
		}
	}

	void push(const K & value) {
		vec->push_back(value);
	}
	void pop() {
		vec->pop_front();
	}

	void print() {
		vec->print();
	}

	K & front() {
		vec[0];
	}
	K & front() const {
		vec[0];
	}
	bool empty() const {
		return vec->empty();
	}
};