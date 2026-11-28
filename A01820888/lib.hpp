#pragma once
#include <iostream>

using namespace std;

void unirMerge(int* arr, int inicio, int mitad, int fin, int& comp);

/*
 * Ordena un arreglo de enteros de menor a mayor comparando cada elemento con todos los siguientes.
 * Complejidad temporal: O(n^2)
 */
void ordenaIntercambio(int* arr, int size, int& comp) {
	comp = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			comp++;
			if (arr[i] > arr[j]) {
				int aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
		}
	}
}

/*
 * Ordena un arreglo de enteros de menor a mayor intercambiando elementos adyacentes desordenados.
 * Complejidad temporal: O(n^2) en el peor caso, O(n) si ya está ordenado.
 */
void ordenaBurbuja(int* arr, int size, int& comp) {
	comp = 0;
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			comp++;
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

/*
 * Divide el arreglo en mitades de forma recursiva y las vuelve a unir ya ordenadas.
 * Complejidad temporal: O(n log n)
 */
void ordenaMerge(int* arr, int start, int end, int& comp) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	ordenaMerge(arr, start, mid, comp);
	ordenaMerge(arr, mid + 1, end, comp);
	unirMerge(arr, start, mid, end, comp);
}

/*
 * Mezcla dos subarreglos ordenados en uno solo manteniendo el orden de menor a mayor.
 * Complejidad temporal: O(n)
 */
void unirMerge(int* arr, int inicio, int mitad, int fin, int& comp) {
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
		comp++;
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

/*
 * Recorre el arreglo elemento por elemento desde el inicio hasta encontrar el valor buscado.
 * Complejidad temporal: O(n)
 */
int busqSecuencial(int* arr, int target, int size, int& comp) {
	comp = 0;
	for (int i = 0; i < size; i++) {
		comp++;
		if (arr[i] == target) return i;
	}

	return -1;
}

/*
 * Busca un valor en un arreglo ordenado dividiendo el rango de búsqueda a la mitad en cada paso.
 * Complejidad temporal: O(log n)
 */
int busqBinaria(int* arr, int target, int size, int& comp) {
	comp = 0;
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int guess = left + (right - left) / 2;
		comp++;
		if (arr[guess] == target) return guess;

		if (arr[guess] < target) left = guess + 1;
		else right = guess - 1;
	}

	return -1;
}
