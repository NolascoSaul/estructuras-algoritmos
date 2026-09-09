/*
	Programa que calcula la suma de los primeros n números naturales
	utilizando tres métodos: iterativo, recursivo y fórmula directa

	Autores:
	- David Medel de la Trinidad	A01821075
	- Erika Danae Arroyo Silva		A0
	- Saul Gabriel Nolasco Cen		A01820888

	Fecha: 01/09/2026
*/

#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull sumaIterativa(int n) {
	ull suma = 0;
	for (int i = 1; i <= n; i++)
		suma += i;

	return suma;
}

ull sumaRecursiva(int n) {
	if (n <= 0)
		return 0;

	return n + sumaRecursiva(n - 1);
}

ull sumaDirecta(int n) {
	ull suma = (ull)n * (n + 1) / 2;
	return suma;
}

int main() {
	int n = 0;
	cin >> n;

	cout << sumaIterativa(n) << endl;
	cout << sumaRecursiva(n) << endl;
	cout << sumaDirecta(n) << endl;

	return 0;
}
