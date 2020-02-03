#pragma once

#include "raylib.h"
#include <iostream>
#include <random>

struct position {
	float x, y;
};

template<typename K>
class tObjectPool {
private:
	K * pool;
	K * object;
	K nothing;
	double thistime;
	position * pos;
	bool * free;
	bool multiples;
	size_t poolCapacity;
	bool clicked;
	position tempMouse;
	int curr = 0;
public:
	tObjectPool() {
		poolCapacity = 0;
		thistime = 0;
		pool = new K[poolCapacity];
		pos = new position[poolCapacity];
		free = new bool[poolCapacity];
		boolReset();
		clicked = false;
		multiples = false;
	}
	tObjectPool(size_t initialCapacity) {
		poolCapacity = initialCapacity;
		thistime = 0;
		pool = K[poolCapacity];
		for (int i = 0; i < poolCapacity; i++) {
			pool[i] = nothing;
		}
		free = new bool[poolCapacity];
		pos = position[poolCapacity];
		boolReset();
		clicked = false;
		multiples = false;
	}
	~tObjectPool() {
		delete[] pool;
		delete[] pos;
		delete[] free;
	}

	void boolReset() {
		for (int i = 0; i < poolCapacity; i++) {
			free[i] = false;
		}
	}

	void zeroed() {
		for (int i = 0; i < poolCapacity; i++) {
			if (!free[i]) {
				pos[i].x = 0;
				pos[i].y = 0;
			}
		}
	}
	void update() {
		for (int i = 0; i < poolCapacity; i++) {
			if (free[i]) {
				pos[i].y += 2;
			}
		}
		cleanUp();
		add();
	}
	void Draw() {
		for (int i = 0; i < poolCapacity; i++) {
			if (free[i]) {
				DrawTexture(pool[i], pos[i].x, pos[i].y, WHITE);
			}
			else {
				break;
			}
		}
	}
	//Checks to see if objects need to be deleted if off screen
	void updateT() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pool[i].id == 0 && pool[i+1].id != 0 && i < poolCapacity + 1) {
				pool[i] = pool[i + 1];
				pos[i] = pos[i + 1];
				free[i] = free[i + 1];
				pool[i + 1] = nothing;
				free[i + 1] = false;
				pos[i + 1].x = 0;
				pos[i + 1].y = 0;
			}
		}
	}
	//Cloning of items
	void updateClicked() {
		if (!free[0]) {
			free[0] = true;
			if (multiples) {
				pool[0] = object[rand() % 4];
			}
			else {
				pool[0] = object[0];
			}
			pos[0].x = (GetScreenWidth() / 2) - (pool[0].width / 2);
			pos[0].y = (GetScreenHeight() / 2) - (pool[0].height / 2);
		}
		int temp;
		if (!clicked) {
			for (int i = 0; i < poolCapacity; i++) {
				if (free[i]) {
					if (mouseTextColl(pool[i], pos[i])) {
						DrawRectangleLines((int)pos[i].x, (int)pos[i].y, (int)pool[i].width, (int)pool[i].height, WHITE);
					}
					if (mouseTextColl(pool[i], pos[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						clicked = true;
						curr++;
						tempMouse.x = (GetMouseX() - pos[i].x);
						tempMouse.y = (GetMouseY() - pos[i].y);
						break;
					}
					else if (mouseTextColl(pool[i], pos[i]) && IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
						recycle(i);
						curr--;
					}
				}
			}
		}
		else {
			if (!free[curr]) {
				if (multiples) {
					pool[curr] = object[rand() % 4];
				}
				else {
					pool[curr] = object[0];
				}
				free[curr] = true;
			}
			pos[curr].x = GetMouseX() - tempMouse.x;
			pos[curr].y = GetMouseY() - tempMouse.y;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				clicked = false;
			}
		}
		if (curr < 0) {
			curr = 0;
		}
	}

	bool mouseTextColl(Texture2D text, position var) {
		if (var.x < GetMouseX() && var.y < GetMouseY() && var.y + text.height > GetMouseY() && var.x + text.width > GetMouseX()) {
			return true;
		}
		return false;
	}

	K * retreive(size_t place) {
		if (pool[place] == nothing) {
			return nothing;
		}
		return pool[place];
	}
	void cleanUp() {
		for (int i = 0; i < poolCapacity; i++) {
			if (pos[i].y >= GetScreenHeight()+(object.height/2)) {
				recycle(i);
			}
		}
	}
	void add() {
		for (int i = 0; i < poolCapacity; i++) {
			if (!free[i]) {
				setActive(i);
			}
		}
	}
	void recycle(size_t place) {
		pool[place] = nothing;
		free[place] = false;
		updateT();
		zeroed();
	}
	void setSize(size_t newCapacity) {
		int temp = poolCapacity;
		poolCapacity = newCapacity;
		K * tempPool = new K[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			if (i < temp) {
				tempPool[i] = pool[i];
			}
			else {
				tempPool[i] = nothing;
			}
		}
		pool = tempPool;
		free = new bool[newCapacity];
		pos = new position[newCapacity];
		boolReset();
	}
	void setActive(size_t size) {
		if (size > poolCapacity) {
			std::cout << "ERROR!";
		}
		else {
			if (GetTime() - thistime > 0.2f) {
				thistime = GetTime();
				pool[size] = object;
				pos[size].x = rand() % GetScreenWidth();
				pos[size].y = -object.height;
				free[size] = true;
			}
		}
	}
	void setObjects(K obj, K obj2, K obj3, K obj4) {
		object = new K[4];
		object[0] = obj;
		object[1] = obj2;
		object[2] = obj3;
		object[3] = obj4;
		multiples = true;
	}
	void setObject(K obj) {
		object = new K[4];
		object[0] = obj;
		multiples = false;
	}

	size_t capacity() {
		return poolCapacity;
	}
};