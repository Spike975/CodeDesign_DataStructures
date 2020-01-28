#pragma once
#include <iostream>
#include <string>
#include <cstring>

int hashCString(char * value,size_t size){
	int hashed = 0;
	for (int i = 0; i < size; i++) {
		hashed += value[i];
	}
	return hashed;
}
int hashStdString(std::string value) {
	int hashed = 0;
	for (int i = 0; i < value.size(); i++) {
		hashed += value[i];
	}
	return hashed;
}

template <typename T>
class tHashmap{

};