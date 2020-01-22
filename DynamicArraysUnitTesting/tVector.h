#pragma once

#include <iostream>

template <typename T>
class tVector{
	const static size_t GROWTH_FACTOR = 2;
private:
	T * arr;
	size_t arrSize;
	size_t arrCapacity;
public:
	tVector() {
		arr = new T[1];
		arrSize = 0;
		arrCapacity = 0;
	}
	tVector(const tVector & vec) {
		arr = vec.arr;
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
	}
	tVector& operator=(const tVector & vec) {
		arr = vec.arr;
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
	}
	T & operator[](size_t index) {
		return arr[index];
	}
	~tVector() {
		delete[] arr;
	}

	bool empty() const {
		if (arrSize) {
			return true;
		}
		return false;
	}
	T * data() {
		return arr;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			std::cout << arr[i] << '\n';
		}
		std::cout << "Capacity: " << capacity() << '\n';
		std::cout << "Size: " << size() << "\n\n";
	}

	void reserve(size_t newCapacity) {
		if(newCapacity > arrCapacity){
			T * temp = new T[newCapacity];
			for (int i = 0; i < newCapacity; i++) {
				if (i < arrCapacity) {
					temp[i] = arr[i];
				}
				else {
					temp[i] = 0;
				}
			}
			delete[] arr;
			arr = temp;
			arrSize = newCapacity;
			arrCapacity = newCapacity;
		}
	}
	void resize(size_t newSize){
		T * temp = new T[newSize];
		for (int i = 0; i < newSize; i++) {
			if (i < arrCapacity) {
				temp[i] = arr[i];
			}
			else {
				temp[i] = 0;
			}
		}
		arr = temp;
		if (newSize < arrSize) {
			arrSize = newSize;
		}
		arrCapacity = newSize;
	}
	void shrinkToFit() {
		T * temp = new T[arrSize];
		for (int i = 0; i < arrSize; i++) {
			temp[i] = arr[i];
		}
		arrCapacity = arrSize;
		arr = temp;
	}
	void clear() {
		delete[] arr;
		arrSize = 0;
		arrCapacity = 0;
	}
	
	void push_front(const T &value) {
		if (arrSize == arrCapacity) {
			T * temp = new T[arrCapacity + 1];
			for (int i = 1; i < arrCapacity+1; i++) {
					temp[i] = arr[i-1];
			}
			temp[0] = value;
			delete[] arr;
			arrCapacity++;
			arrSize++;
			arr = temp;
		}
		else if (arrSize < arrCapacity) {
			T * temp = new T[arrCapacity];
			for (int i = 1; i < arrCapacity; i++) {
				temp[i+1] = arr[i];
			}
			temp[0] = value;
			delete[] arr;
			arrSize++;
			arr = temp;
		}
	}
	void pop_front() {
		T * temp = new T[arrCapacity];
		for (int i = 1; i < arrCapacity; i ++) {
			temp[i - 1] = arr[i];
		}
		temp[arrCapacity] = 0;
		delete[] arr;
		arrSize--;
		arr = temp;
	}
	void push_back(const T &value) {
		if (arrSize == arrCapacity) {
			T * temp = new T[arrCapacity + 1];
			for (int i = 0; i < arrCapacity; i++) {
				temp[i] = arr[i];
			}
			temp[arrCapacity] = value;
			arrCapacity++;
			arrSize++;
			delete[] arr;
			arr = temp;
		}
		else if( arrSize < arrCapacity) {
			T * temp = new T[arrCapacity];
			for (int i = 0; i < arrCapacity; i++) {
				temp[i] = arr[i];
			}
			temp[arrSize] = value;
			arrSize++;
			delete[] arr;
			arr = temp;
		}
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
		delete[] arr;
		arr = temp;
		arrSize--;
	}

	T & at(size_t index) {
		return arr[index];
	}

	size_t size() const {
		return arrSize;
	}
	size_t capacity() const {
		return arrCapacity;
	}
};