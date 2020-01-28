#pragma once

#include <iostream>
#include <string>

template<typename T>
class tObjectPool{
private:
	T * pool;
	bool * free;
	size_t poolCapacity;
public:
	tObjectPool() {
		poolCapacity = 0;
	}
	tObjectPool(size_t initialCapacity) {
		poolCapacity = initialCapacity;
	}
	~tObjectPool() {
		delete pool;
		delete free;
	}

	T * retreive() {
		if (pool == NULL) {
			return NULL;
		}
		return pool;
	}
	void recycle(T * obj) {

	}

	size_t capacity() {
		return poolCapacity;
	}
};