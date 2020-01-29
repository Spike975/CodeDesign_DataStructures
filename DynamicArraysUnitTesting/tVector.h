#pragma once

#include <iostream>

template <typename K>
class tVector{
	const static size_t GROWTH_FACTOR = 2;
private:
	K * arr;
	size_t arrSize;
	size_t arrCapacity;
public:
	tVector() {
		arr = new K[1];
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
	K & operator[](size_t index) {
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
	K * data() {
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
			K * temp = new K[newCapacity];
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
		K * temp = new K[newSize];
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
		K * temp = new K[arrSize];
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
	
	void push_front(const K &value) {
		if (arrSize == arrCapacity) {
			K * temp = new K[arrCapacity + 1];
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
			K * temp = new K[arrCapacity];
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
		K * temp = new K[arrCapacity];
		for (int i = 1; i < arrCapacity; i ++) {
			temp[i - 1] = arr[i];
		}
		temp[arrCapacity] = 0;
		delete[] arr;
		arrSize--;
		arr = temp;
	}
	void push_back(const K &value) {
		if (arrSize == arrCapacity) {
			K * temp = new K[arrCapacity + 1];
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
			K * temp = new K[arrCapacity];
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
		K * temp = new K[arrCapacity];
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

	K & at(size_t index) {
		return arr[index];
	}

	size_t size() const {
		return arrSize;
	}
	size_t capacity() const {
		return arrCapacity;
	}
};