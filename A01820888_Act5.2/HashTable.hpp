#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Ip.hpp"

using namespace std;

// Número primo más grande menor a 65536
const int TABLE_SIZE = 65521;

struct HashSlot {
	bool occupied = false;
	string network;
	int accessCount = 0;
	vector<Ip> uniqueIps;
};

class HashTable {
private:
	HashSlot table[TABLE_SIZE];

	/*
	 * Función Hash propuesta:
	 * (firstByte * 256 + secondByte) y aplicar módulo 65521.
	 *
	 * Justificación:
	 * Es una función sencilla y rápida que convierte los dos primeros octetos en un número único
	 * entre 0 y 65535. Al aplicar módulo con el primo 65521, se distribuyen las redes de forma
	 * uniforme y se reducen las colisiones.
	 *
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int hashFunction(int firstByte, int secondByte) {
		return (firstByte * 256 + secondByte) % TABLE_SIZE;
	}

	/*
	 * Mezcla dos subvectores ordenados de IPs en uno solo de manera ascendente.
	 * Complejidad temporal: O(k), donde k es el tamaño del rango combinado.
	 * Complejidad espacial: O(k) por los vectores temporales left y right.
	 */
	void merge(vector<Ip>& arr, int start, int mid, int end) {
		int sizeL = mid - start + 1;
		int sizeR = end - mid;

		vector<Ip> left(arr.begin() + start, arr.begin() + mid + 1);
		vector<Ip> right(arr.begin() + mid + 1, arr.begin() + end + 1);

		int i = 0;
		int j = 0;
		int k = start;

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

	/*
	 * Divide el vector de IPs en mitades de forma recursiva y las une ordenadas.
	 * Complejidad temporal: O(k log k), donde k es la cantidad de IPs.
	 * Complejidad espacial: O(k) por los vectores auxiliares y la pila de recursión.
	 */
	void mergeSort(vector<Ip>& arr, int start, int end) {
		if (start >= end) return;

		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}

public:
	/*
	 * Inserta una IP en la tabla hash agrupándola por red.
	 * Complejidad temporal: O(1) en promedio, O(n) en el peor caso (donde n es TABLE_SIZE).
	 * Complejidad espacial: O(1) auxiliar.
	 */
	void insert(Ip& ip) {
		string network = ip.getNetwork();
		int startIndex = hashFunction(ip.getFirstByte(), ip.getSecondByte());

		for (int i = 0; i < TABLE_SIZE; i++) {
			int index = (startIndex + i) % TABLE_SIZE;

			if (!table[index].occupied) {
				table[index].occupied = true;
				table[index].network = network;
				table[index].accessCount = 1;
				table[index].uniqueIps.push_back(ip);
				return;
			}

			if (table[index].network == network) {
				table[index].accessCount++;

				bool alreadyExists = false;
				for (int j = 0; j < (int)table[index].uniqueIps.size(); j++) {
					if (table[index].uniqueIps[j] == ip) {
						alreadyExists = true;
						break;
					}
				}

				if (!alreadyExists) {
					table[index].uniqueIps.push_back(ip);
				}
				return;
			}
		}

		cout << "Tabla llena, imposible meter más datos" << endl;
	}

	/*
	 * Ordena de manera ascendente las IPs únicas de cada red almacenada.
	 * Complejidad temporal: O(k log k) por cada red, donde k es la cantidad de IPs únicas.
	 * Complejidad espacial: O(k) por los vectores auxiliares del merge sort.
	 */
	void sortIps() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (table[i].occupied && !table[i].uniqueIps.empty()) {
				mergeSort(table[i].uniqueIps, 0, (int)table[i].uniqueIps.size() - 1);
			}
		}
	}

	/*
	 * Busca una red en la tabla hash y muestra su resumen en pantalla.
	 * Complejidad temporal: O(1) en promedio, O(n) en el peor caso (donde n es TABLE_SIZE).
	 * Complejidad espacial: O(1) auxiliar.
	 */
	void displayNetwork(string& network) {
		int firstByte = 0, secondByte = 0;
		sscanf(network.c_str(), "%d.%d", &firstByte, &secondByte);

		int startIndex = hashFunction(firstByte, secondByte);

		for (int i = 0; i < TABLE_SIZE; i++) {
			int index = (startIndex + i) % TABLE_SIZE;

			if (!table[index].occupied) {
				break;
			}

			if (table[index].network == network) {
				cout << table[index].network << "\n";
				cout << table[index].accessCount << "\n";
				cout << table[index].uniqueIps.size() << "\n";

				for (int j = 0; j < (int)table[index].uniqueIps.size(); j++) {
					cout << table[index].uniqueIps[j].toString() << "\n";
				}
				return;
			}
		}

		cout << network << "\n";
		cout << 0 << "\n";
		cout << 0 << "\n";
	}
};
