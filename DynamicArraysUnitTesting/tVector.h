#pragma once

#include <iostream>

template <typename T>
class tVector{
	const static size_t GROWTH_FACTOR = 2;
private:
	T *arr;
	size_t arrSize;
	size_t arrCapacity;
public:
	tVector() {
		arr = new T[0];
		arrSize = 0;
		arrCapacity = 0;
	}
	~tVector() {
		delete[] arr;
	}

	T *data() {
		return *arr;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			std::cout << arr[i];
		}
	}

	void reserve(size_t newCapacity) {
		T * temp = new T[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			if (i < arrCapacity) {
				temp[i] = arr[i];
			}
			else {
				temp[i] = 0;
			}
		}
		arr = temp;
		if (newCapacity < arrSize) {
			arrSize = newCapacity;
		}
		arrCapacity = newCapacity;
		delete[] temp;
	}

	void push_back(const T &value) {
		T * temp = new T[arrCapacity + 1];
		for (int i = 0; i < arrCapacity; i++) {
			temp[i] = arr[i];
		}
		temp[arrCapacity] = value;
		arr = temp;
		arrSize++;
		arrCapacity++;
		delete[] temp;
	}
	void pop_back() {
		T * temp = new T[arrCapacity];
		for (int i = 0; i < arrCapacity; i++) {
			if (i < arrSize) {
				temp[i] = arr[i];
			}
			else {
				temp[i] = 0;
			}
		}
		arr = temp;
		arrSize--;
		delete[] temp;
	}

	T &at(size_t index) {
		return arr[index];
	}

	size_t size() const {
		return arrSize;
	}
	size_t capacity() const {
		return arrCapacity;
	}
};