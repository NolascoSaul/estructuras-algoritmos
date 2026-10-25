#pragma once

#include <iostream>
#include <algorithm>
#include "queue.hpp"
using namespace std;


struct Node {
	Node* right;
	Node* left;
	int data;

	Node(int value) : data(value), right(nullptr), left(nullptr) {}
};

class BinSearchTree {
private:
	/*
	- Elimina recursivamente todos los nodos del árbol (Postorden).
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h) por la pila de recursión.
	*/
	void clear(Node* node) {
		if (node) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	/*
	- Recorrido Raíz-Izquierda-Derecha.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h) por la pila de recursión.
	*/
	void preorder(Node* root) {
		if (root) {
			cout << root->data << " ";
			preorder(root->left);
			preorder(root->right);
		}
	}

	/*
	- Recorrido Izquierda-Raíz-Derecha.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h) por la pila de recursión.
	*/
	void inorder(Node* root) {
		if (root) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}

	/*
	- Recorrido Izquierda-Derecha-Raíz.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h) por la pila de recursión.
	*/
	void postorder(Node* root) {
		if (root) {
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
	}

	/*
	- Recorrido por niveles de arriba hacia abajo usando una Cola FIFO.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(W) donde W es el ancho máximo del árbol.
	*/
	void levelorder(Node* root) {
		if (!root) return;

		Queue<Node*> queue;
		queue.push(root);

		Node* curr = nullptr;

		while (!queue.isEmpty()) {
			curr = queue.front();
			queue.pop();

			cout << curr->data << " ";

			if (curr->left) queue.push(curr->left);

			if (curr->right) queue.push(curr->right);
		}
	}
public:
	Node* root;

	BinSearchTree() : root(nullptr) {}

	~BinSearchTree() {
		clear(root);
	}

	/*
	- Inserta un nuevo valor de forma iterativa, ignorando duplicados.
	- Complejidad Temporal: O(h)
	- Complejidad Espacial: O(1)
	*/
	void insert(int value) {
		if (root == nullptr) {
			root = new Node(value);
			return;
		}

		Node* current = root;
		Node* parent = nullptr;

		while (current) {
			if (current->data == value) return;

			parent = current;
			if (value < current->data)
				current = current->left;
			else
				current = current->right;
		}

		if (value < parent->data)
			parent->left = new Node(value);
		else
			parent->right = new Node(value);
	}

	/*
	- Selector de tipo de recorrido.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: Depende del recorrido elegido.
	*/
	void traversal(int n) {
		switch (n) {
		case 1:
			preorder(root);
			cout << endl;
			break;
		case 2:
			inorder(root);
			cout << endl;
			break;
		case 3:
			postorder(root);
			cout << endl;
			break;
		case 4:
			levelorder(root);
			cout << endl;
			break;
		}
	}

	/*
	- Calcula el número de niveles del árbol recursivamente.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h) por la pila de recursión.
	*/
	int height(Node* root) {
		if (!root) return 0;

		return 1 + max(height(root->left), height(root->right));
	}

	/*
	- Imprime el camino desde la raíz hasta el nodo buscado de forma iterativa.
	- Complejidad Temporal: O(h)
	- Complejidad Espacial: O(1)
	*/
	void ancestors(int value) {
		if (whatlevelamI(value) == -1) return;

		Node* current = root;

		while (current) {
			if (current->data == value) break;

			cout << current->data << " ";

			if (value < current->data)
				current = current->left;
			else
				current = current->right;
		}

		cout << endl;
	}

	/*
	- Elimina un nodo iterativamente manejando los 3 casos (0, 1 o 2 hijos).
	- Complejidad Temporal: O(h)
	- Complejidad Espacial: O(1)
	*/
	void erase(int value) {
		Node* current = root;
		Node* parent = nullptr;

		while (current && current->data != value) {
			parent = current;
			if (value < current->data)
				current = current->left;
			else
				current = current->right;
		}

		if (!current) return;

		if (!current->left || !current->right) {
			Node* child = current->left ? current->left : current->right;

			if (!parent)
				root = child;
			else if (parent->left == current)
				parent->left = child;
			else
				parent->right = child;

			delete current;
		} else {
			Node* successorParent = current;
			Node* successor = current->right;

			while (successor->left) {
				successorParent = successor;
				successor = successor->left;
			}

			current->data = successor->data;

			if (successorParent->left == successor)
				successorParent->left = successor->right;
			else
				successorParent->right = successor->right;

			delete successor;
		}
	}

	/*
	- Busca la profundidad iterativamente contando los saltos desde la raíz.
	- Complejidad Temporal: O(h)
	- Complejidad Espacial: O(1)
	*/
	int whatlevelamI(int value) {
		int level = 0;

		Node* current = root;
		while (current) {
			if (value == current->data) return level;

			if (value < current->data)
				current = current->left;
			else
				current = current->right;

			level++;
		}

		return -1;
	}
};
