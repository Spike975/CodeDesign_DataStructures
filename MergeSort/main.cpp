#include <random>
#include <iostream>
#include <time.h>
#include "mergeSort.h"

int main() {
	srand(time(NULL));
	int * size = new int;
	*size = 14;
	int * arr = new int[*size];
	for (int i = 0; i < *size; i++) {
		arr[i] = rand() % 50 + 1;
	}
	for (int i = 0; i < *size; i++) {
		std::cout << arr[i] <<"\n";
	}
	std::cout << '\n';

	mergeSort(arr, 0, *size-1);

	for (int i = 0; i < *size; i++) {
		std::cout << arr[i] << "\n";
	}

	delete[] arr;
	delete size;
	return 0;
}