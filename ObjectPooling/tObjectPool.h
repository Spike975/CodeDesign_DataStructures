#pragma once

#include <iostream>
#include <string>

template<typename K>
class tObjectPool{
private:
	K * pool;
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

	K * retreive() {
		if (pool == NULL) {
			return NULL;
		}
		return pool;
	}
	void recycle(K * obj) {

	}

	size_t capacity() {
		return poolCapacity;
	}
};