#pragma once

#include "raylib.h"
#include <iostream>
#include <random>

struct position {
	float x, y;
};

template<typename T>
class tObjectPool {
private:
	T * pool;
	T object;
	T nothing;
	double thistime;
	position * pos;
	bool * free;
	size_t poolCapacity;
public:
	tObjectPool() {
		poolCapacity = 0;
		thistime = 0;
		pool = new T[poolCapacity];
		pos = new position[poolCapacity];
	}
	tObjectPool(size_t initialCapacity) {
		poolCapacity = initialCapacity;
		thistime = 0;
		pool = T[poolCapacity];
		for (int i = 0; i < poolCapacity; i++) {
			pool[i] = nothing;
		}
		pos = position[poolCapacity];
	}
	~tObjectPool() {
		delete[] pool;
		delete[] pos;
		delete free;
	}

	void zeroed() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i] == NULL) {
				pos[i]->x = 0;
				pos[i]->y = 0;
			}
		}
	}
	void update() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i].id != nothing.id) {
				pos[i].y += 2;
			}
		}
	}
	void Draw() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i].id != nothing.id) {
				DrawTexture(pool[i], pos[i].x, pos[i].y, WHITE);
			}
			else {
				break;
			}
		}
	}
	void updateT() {
		T * temp;
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i] == nothing && pool[i+1] != nothing && i < poolCapacity + 1) {
				temp = pool[i];
				pool[i] = pool[i + 1];
				pool = temp;
			}
		}
		delete temp;
	}

	T * retreive(size_t place) {
		if (pool[place] == nothing) {
			return NULL;
		}
		return pool[place];
	}
	void cleanUp() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pos[i].y >= GetScreenHeight()+object.height) {
				pool[i] = nothing;
			}
		}
	}
	void add() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i].id == nothing.id) {
				setActive(i);
			}
		}
	}
	void recycle(size_t place) {
		pool[place] = nothing;
		updateT();
		zeroed();
	}
	void setSize(size_t newCapacity) {
		int temp = poolCapacity;
		poolCapacity = newCapacity;
		T * tempPool = new T[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			if (i < temp) {
				tempPool[i] = pool[i];
			}
			else {
				tempPool[i] = nothing;
			}
		}
		pool = tempPool;
	}
	void setActive(size_t size) {
		if (size > poolCapacity) {
			std::cout << "ERROR!";
		}
		else {
			if (GetTime() - thistime > .1) {
				thistime = GetTime();
				pool[size] = object;
				pos[size].x = rand() % GetScreenWidth();
				pos[size].y = -object.height;
			}
		}
	}
	void setObject(T obj) {
		object = obj;
	}

	size_t capacity() {
		return poolCapacity;
	}
};