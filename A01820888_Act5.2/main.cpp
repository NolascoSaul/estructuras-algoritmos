/*
	Programa que lee los registros del archivo bitacora.txt, agrupa las direcciones IP por red
	en una tabla hash y despliega el resumen ordenado de cada dominio consultado.

	Integrantes:
	- Saúl Gabriel Nolasco Cen - A01820888
	- Judith Juquila Lopez Estudillo - A00845789

	Fecha de creacion: 27/11/2026
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Ip.hpp"
#include "HashTable.hpp"

using namespace std;

/*
 * Lee el archivo bitacora.txt línea por línea e inserta cada IP en la tabla hash.
 * Complejidad temporal: O(m), donde m es el número de registros en el archivo.
 * Complejidad espacial: O(1) auxiliar.
 */
void readLogFile(HashTable& table) {
	ifstream file("bitacora.txt");
	if (!file.is_open()) {
		cout << "Error al abrir bitacora.txt\n";
		return;
	}

	string month, day, timeStr, ipStr, restOfLine;
	while (file >> month >> day >> timeStr >> ipStr) {
		getline(file, restOfLine);
		Ip ip(ipStr);
		table.insert(ip);
	}

	file.close();
}

int main() {
	HashTable table;

	readLogFile(table);
	table.sortIps();

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string domain;
		cin >> domain;

		if (i > 0) cout << "\n";
		table.displayNetwork(domain);
	}

	return 0;
}
