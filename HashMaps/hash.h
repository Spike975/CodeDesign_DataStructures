#pragma once
#include <iostream>
#include <string>

template <typename K, typename V>
class tHashmap {
private:
	struct hashData {
		int hash;
		K key;
		V value;
	};
	hashData * data;
	size_t dataCapacity;
	int hashed(std::string value) {
		int hashed = 0;
		for (int i = 0; i < value.size(); i++) {
			hashed += value[i];
		}
		return hashed;
	}
public:
	tHashmap() {
		data = new hashData[1];
		dataCapacity = 1;
		reset();
	}
	tHashmap(size_t size) {
		dataCapacity = size;
		data = new hashData[dataCapacity];
		reset();
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

	void reset() {
		for (int i = 0; i < dataCapacity; i++) {
			data[i].hash = 0;
			data[i].value = 0;
		}
	}
	bool empty() {
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i] != NULL) {
				return false;
			}
		}
		return true;
	}

	size_t size(){
		size_t size = 0;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key != "") {
				size++;
			}
		}
		return size;
	}
	size_t count(const K & key) {
		size_t size = 0;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key){
				size++;
			}
		}
		return size;
	}
	V & operator[] (const K & key) {
		int temp;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key && data[i].hash == hashed(key)) {
				return data[i].value;
			}
			else{
				temp = i;
			}

		}
		return data[temp].value;
	}
	void set(const K & key, const V & value) {
		int free;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == ""){
				free = i;
				break;
			}
			if (i == dataCapacity-1) {
				std::cout << "No avalible space\n";//Maybe do something for adding it anyway
				return;
			}
		}
		data[free].value = value;
		data[free].key = key;
		data[free].hash = hashed(key);
	}
	V & at(const K & key) {
		int temp;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key) {
				return data[i].value;
			}
			else {
				temp = i;
			}

		}
		std::cout << "No data at given key";
		return data[temp].value;
	}
	const V & operator[] (const K & key) const {
		return data[hashed(key) % dataCapacity];
	}
	void setSize(size_t newCapacity) {
		hashData * temp = new hashData[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			if (i < dataCapacity) {
				temp[i] = data[i];
			}
			else {
				temp[i].hash = 0;
				temp[i].value = 0;
			}
		}
		dataCapacity = newCapacity;
		data = temp;
	}
	int hashCString(char * value, size_t size) {
		int hashed = 0;
		for (int i = 0; i < size; i++) {
			hashed += value[i];
		}
		return hashed;
	}
};