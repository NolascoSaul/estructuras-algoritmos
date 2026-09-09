#include "lib.hpp"
#include <iostream>

using namespace std;

void ordenaIntercambio(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
		}
	}
}

void ordenaBurbuja(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
				swapped = true;
			}
		}

		if (!swapped) break;
	}
}

void ordenaMerge(int* arr, int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	ordenaMerge(arr, start, mid);
	ordenaMerge(arr, mid + 1, end);
	unirMerge(arr, start, mid, end);
}

void unirMerge(int* arr, int inicio, int mitad, int fin) {
	int sizeL = mitad - inicio + 1;
	int sizeR = fin - mitad;

	int left[sizeL];
	int right[sizeR];

	for (int i = 0; i < sizeL; i++)
		left[i] = arr[inicio + i];
	for (int j = 0; j < sizeR; j++)
		right[j] = arr[mitad + j + 1];

	int i = 0, j = 0, k = inicio;

	while (i < sizeL && j < sizeR) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while (i < sizeL)
		arr[k++] = left[i++];

	while (j < sizeR)
		arr[k++] = right[j++];
}

int busqSecuencial(int* arr, int target, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) return i;
	}

	return -1;
}


int busqBinaria(int* arr, int target, int size) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int guess = left + (right - left) / 2;
		if (arr[guess] == target) return guess;

		if (arr[guess] < target) left = guess + 1;
		else right = guess - 1;
	}

	return -1;
}
