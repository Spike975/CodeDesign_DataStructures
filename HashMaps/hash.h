#pragma once
#include <iostream>
#include <string>

template <typename T, typename K>
class tHashmap{
private:
	K * data;
	size_t dataCapacity;
public:
	int hashStdString(std::string value) {
		int hashed = 0;
		for (int i = 0; i < value.size(); i++) {
			hashed += value[i];
		}
		return hashed;
	}
	tHashmap() {
		data = K[1];
		dataCapacity = 1;
	}
	tHashmap(size_t size) {
		dataCapacity = size;
		data = new K[dataCapacity];
	}
	tHashmap(const tHashmap & value) {
		data = value->data;
		dataCapacity = value->dataCapacity;
	}
	tHashmap operator= (const tHashmap & value) {
		data = value->data;
		dataCapacity = value->dataCapacity;
	}
	~tHashmap() {
		delete[] data;
	}

	K & operator[] (T & key) {
		if (data[hashStdString(key)] != NULL) {
			return data[hashStdString(key)];
		}
		return NULL;
	}
	int hashCString(char * value, size_t size) {
		int hashed = 0;
		for (int i = 0; i < size; i++) {
			hashed += value[i];
		}
		hashed = hashed % dataCapacity;
		return hashed;
	}
	void setKey(T & value, K other) {
		if (data[hashStdString(value)] != NULL) {
			data[hashStdString(value)] = other;
		}
		else {
			std::cout << "Entry already used";
		}
	}
};