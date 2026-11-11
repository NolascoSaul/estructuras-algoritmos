/*
	Programa que lee una matriz de adyacencia e imprime
	la matriz, la lista de adyacencia correspondiente y
	los recorridos Breadth-First Search (BFS) y
	Depth-First Search (DFS).

	Autores:
	- Judith Juquila Lopez Estudillo	A00845789
	- Saul Gabriel Nolasco Cen			A01820888

	Fecha: 10/11/2026
*/

#include <iostream>
#include <vector>
#include "queue.hpp"
using namespace std;

/**
 * Imprime una matriz de adyacencia.
 *
 * Complejidad temporal: O(n^2).
 *
 * Complejidad espacial auxiliar: O(1).
 *
 * @param matrix Matriz de adyacencia que se imprimirá.
 * @param size Número de filas y columnas de la matriz.
 */
void printMatrix(vector<vector<bool>>& matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

string getLabel(int n) {
	string label = "";
	while (n >= 0) {
		label = char('A' + (n % 26)) + label;
		n = (n / 26) - 1;
	}
	return label;
}

/**
 * Imprime la lista de adyacencia de un grafo.
 *
 * Complejidad temporal: O(V + E).
 *
 * Complejidad espacial auxiliar: O(1).
 *
 * @param list Lista de adyacencia del grafo.
 * @param numNodes Número de vértices del grafo.
 */
void printList(vector<vector<int>>& list, int numNodes) {
	for (int i = 0; i < numNodes; i++) {
		cout << getLabel(i);

		int sizeList = list[i].size();
		if (sizeList > 0) cout << " - ";

		for (int j = 0; j < sizeList; j++) {
			cout << getLabel(list[i][j]);
			if (j < sizeList - 1) cout << " - ";
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * Realiza un recorrido Breadth-First Search (BFS) desde un vértice inicial.
 *
 * Complejidad temporal: O(V + E).
 *
 * Complejidad espacial auxiliar: O(V), por la cola.
 *
 * @param list Lista de adyacencia del grafo.
 * @param visited Vector que indica si cada vértice ya fue visitado.
 * @param startVertex Vértice desde el cual inicia el recorrido.
 */
void BFS(vector<vector<int>>& list, vector<bool>& visited, int startVertex) {
	Queue<int> q;
	visited[startVertex] = true;
	q.push(startVertex);

	while (!q.isEmpty()) {
		int currVertex = q.pop();
		cout << getLabel(currVertex) << " ";

		for (int vertex : list[currVertex]) {
			if (!visited[vertex]) {
				visited[vertex] = true;
				q.push(vertex);
			}
		}
	}
}

/**
 * Realiza un recorrido Depth-First Search (DFS) desde un vértice dado.
 *
 * Complejidad temporal: O(V^2)
 *
 * Complejidad espacial auxiliar: O(V), por la pila de recursión.
 *
 * @param matrix Matriz de adyacencia del grafo.
 * @param visited Vector que indica si cada vértice ya fue visitado.
 * @param vertex Vértice actual del recorrido.
 */
void DFS(vector<vector<bool>>& matrix, vector<bool>& visited, int vertex) {
	visited[vertex] = true;

	cout << getLabel(vertex) << " ";

	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[vertex][i] == 1 && !visited[i])
			DFS(matrix, visited, i);
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> matrix(n, vector<bool>(n));
	vector<vector<int>> list(n);
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool tmp;
			cin >> tmp;

			matrix[i][j] = tmp;
			if (tmp == 1) list[i].push_back(j);
		}
	}

	printMatrix(matrix, n);
	printList(list, n);

	BFS(list, visited, 0);
	cout << endl << endl;

	visited.assign(n, false);

	DFS(matrix, visited, 0);
	cout << endl;

	return 0;
}
