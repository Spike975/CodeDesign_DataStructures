#include "mergeSort.h"
#include <iostream>

void merge(int * arr, size_t first, size_t middle, size_t last) {
	int left = middle - first+1;
	int right = last - middle;

	int * arrLeft = new int[left];
	int * arrRight = new int[right];

	for (int i = 0; i < left; i++) {
		arrLeft[i] = arr[first+i];
	}
	for (int i = 0; i < right; i++) {
		arrRight[i] = arr[middle+i+1];
	}

	int x = 0;
	int y = 0;

	for (int i = first; i <= last;i++) {
		if (y >= right || (x < left && arrLeft[x] <= arrRight[y])) {
			arr[i] = arrLeft[x];
			x++;
		}
		else {
			arr[i] = arrRight[y];
			y++;
		}
	}
}

void mergeSort(int * arr, size_t first, size_t last) {
	if (first < last) {
		int middle = (first + last) / 2;
		mergeSort(arr, first, middle);
		mergeSort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
}