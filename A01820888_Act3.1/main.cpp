/*
	Programa que lee un número de nodos y los inserta
	en un árbol binario de búsqueda (BST), para
	posteriormente realizar operaciones avanzadas.

	Autores:
	- David Medel de la Trinidad		A01821075
	- Judith Juquila Lopez Estudillo	A00845789
	- Saul Gabriel Nolasco Cen			A01820888

	Fecha: 24/10/2026
*/

#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
	BinSearchTree bst;
	int val;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		bst.insert(val);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> val;
		bst.erase(val);
	}

	bst.traversal(1);
	bst.traversal(2);
	bst.traversal(3);
	bst.traversal(4);

	cout << bst.height(bst.root) << endl;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> val;
		bst.ancestors(val);
	}

	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		cin >> val;
		cout << bst.whatlevelamI(val) << endl;
	}

	return 0;
}
