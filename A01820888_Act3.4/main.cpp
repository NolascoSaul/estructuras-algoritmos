/*
	Programa que lee una bitácora de accesos, extrae IPs, fechas y horas,
	y las almacena en un Árbol Binario de Búsqueda (BST) ordenadas de menor a mayor.
	Finalmente, extrae e imprime los 5 registros con los valores de IP más altos.

	Autores:
	- David Medel de la Trinidad        A01821075
	- Judith Juquila Lopez Estudillo    A00845789
	- Saul Gabriel Nolasco Cen          A01820888

	Fecha: 24/10/2026
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
using namespace std;

using Llave = array<int, 10>;

struct Nodo {
	Llave llave;
	string linea;
	Nodo* izq = nullptr;
	Nodo* der = nullptr;
	Nodo(const Llave& k, const string& l) : llave(k), linea(l) {}
};

class BST {
public:
	BST() : raiz(nullptr) {}
	~BST() { liberar(); }

	/*
	- Inserta un nuevo registro en el BST iterativamente usando la Llave para ordenar.
	- Complejidad Temporal: O(h)
	- Complejidad Espacial: O(1)
	*/
	void insertar(const Llave& k, const string& linea) {
		Nodo* nuevo = new Nodo(k, linea);
		if (!raiz) { raiz = nuevo; return; }
		Nodo* actual = raiz;
		while (true) {
			if (k < actual->llave) {
				if (!actual->izq) { actual->izq = nuevo; return; }
				actual = actual->izq;
			} else {
				if (!actual->der) { actual->der = nuevo; return; }
				actual = actual->der;
			}
		}
	}

	/*
	- Realiza un recorrido Inorden Inverso (Derecha-Raíz-Izquierda) iterativo para obtener los k mayores.
	- Complejidad Temporal: O(h + k)
	- Complejidad Espacial: O(h) por la pila del recorrido.
	*/
	void imprimirCincoMayores(int k) const {
		vector<Nodo*> pila;
		Nodo* actual = raiz;
		int impresos = 0;
		while ((actual || !pila.empty()) && impresos < k) {
			while (actual) {
				pila.push_back(actual);
				actual = actual->der;
			}
			actual = pila.back();
			pila.pop_back();
			cout << actual->linea << "\n";
			impresos++;
			actual = actual->izq;
		}
	}

private:
	Nodo* raiz;

	/*
	- Libera la memoria de todos los nodos usando un recorrido iterativo con pila.
	- Complejidad Temporal: O(N)
	- Complejidad Espacial: O(h)
	*/
	void liberar() {
		vector<Nodo*> pila;
		if (raiz) pila.push_back(raiz);
		while (!pila.empty()) {
			Nodo* n = pila.back();
			pila.pop_back();
			if (n->izq) pila.push_back(n->izq);
			if (n->der) pila.push_back(n->der);
			delete n;
		}
		raiz = nullptr;
	}
};

/*
- Convierte el string del mes (ej. "Jan") a su valor numérico (1-12) para poder ordenarlo.
- Complejidad Temporal: O(1)
- Complejidad Espacial: O(1)
*/
int mesANumero(const string& m) {
	static const char* meses[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < 12; i++)
		if (m == meses[i]) return i + 1;
	return 0;
}

/*
- Extrae la IP, puerto, fecha y hora de la línea de texto y construye un array (Llave) con el orden de prioridad requerido.
- Complejidad Temporal: O(1)
- Complejidad Espacial: O(1)
*/
bool crearLlave(const string& linea, Llave& k) {
	istringstream ss(linea);
	string mes, hora, ipPuerto;
	int dia;
	if (!(ss >> mes >> dia >> hora >> ipPuerto)) return false;

	int a, b, c, d, puerto, h, m, s;
	char p1, p2, p3, dosPuntos, c1, c2;
	istringstream ssIp(ipPuerto);
	if (!(ssIp >> a >> p1 >> b >> p2 >> c >> p3 >> d >> dosPuntos >> puerto))
		return false;
	istringstream ssHora(hora);
	if (!(ssHora >> h >> c1 >> m >> c2 >> s)) return false;

	k = { a, b, c, d, puerto, mesANumero(mes), dia, h, m, s };
	return true;
}

int main() {
	ifstream archivo("bitacora.txt");
	if (!archivo) {
		return 1;
	}
	BST arbol;
	string linea;
	while (getline(archivo, linea)) {
		if (!linea.empty() && linea.back() == '\r') linea.pop_back();
		if (linea.empty()) continue;
		Llave k;
		if (crearLlave(linea, k)) arbol.insertar(k, linea);
	}

	arbol.imprimirCincoMayores(5);
	return 0;
}
