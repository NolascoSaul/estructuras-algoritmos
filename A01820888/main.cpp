/*
	Programa que ordena un arreglo de números usando intercambio, burbuja y merge sort,
	cuenta sus comparaciones y realiza consultas con búsqueda secuencial y binaria.

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

	int compInter = 0;
	int compBubble = 0;
	int compMerge = 0;

	ordenaIntercambio(arrInter, n, compInter);
	ordenaBurbuja(arrBubble, n, compBubble);
	ordenaMerge(arrMerge, 0, n - 1, compMerge);

	cout << compInter << " " << compBubble << " " << compMerge << endl;

	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int target;
		cin >> target;

		int compSec = 0;
		int compBin = 0;

		int pos = busqSecuencial(arrBubble, target, n, compSec);
		busqBinaria(arrBubble, target, n, compBin);

		cout << pos << " " << compSec << " " << compBin << endl;
	}

	return 0;
}
