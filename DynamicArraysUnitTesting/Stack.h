#pragma once

template <typename T>
class tStack{
private:
	tVector<T> * vec;
public:
	tStack() {
		vec = new tVector<T>;
	}
	T & operator[](size_t index) {
		return vec.at(index);
	}

	void push(const T & value) {
		vec->push_front(value);
	}
	void pop() {
		vec->pop_front();
	}

	T & top() {
		return vec[0];
	}

	size_t size() const {
		return vec->size();
	}
	bool empty() const {
		return vec->empty();
	}
};


template <typename T>
class tQueue{
private:
	tVector<T> * vec;
public:
	tQueue() {
		vec = new tVector<T>;
	}
	tQueue(size_t count, const T & value) {
		vec = new tVector<T>;
		for (int i = 0; i < count; i++) {
			push(value);
		}
	}

	void push(const T & value) {
		vec->push_back(value);
	}
	void pop() {
		vec->pop_front();
	}

	void print() {
		vec->print();
	}

	T & front() {
		vec[0];
	}
	T & front() const {
		vec[0];
	}
	bool empty() const {
		return vec->empty();
	}
};