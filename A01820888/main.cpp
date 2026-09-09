/*
	Programa que...

	Autores:
	- David Medel de la Trinidad	A01821075
	- Erika Danae Arroyo Silva		A01820835
	- Saul Gabriel Nolasco Cen		A01820888

	Fecha: 01/09/2026
*/

#include <iostream>
#include "lib.hpp"
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	int arrInter[n];
	int arrBubble[n];
	int arrMerge[n];

	for (int i = 0; i < n; i++) {
		int aux;
		cin >> aux;

		arrInter[i] = aux;
		arrBubble[i] = aux;
		arrMerge[i] = aux;
	}

	ordenaIntercambio(arrInter, n);
	ordenaBurbuja(arrBubble, n);
	ordenaMerge(arrMerge, 0, n - 1);

	cout << "AQUI IRIAN LAS COMPARACIONES DE CADA ORDENAMIENTO" << endl;

	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int target;
		cin >> target;

		cout << busqBinaria(arrBubble, target, n) << " ";
		cout << "bS bB" << endl;
	}

	return 0;
}
