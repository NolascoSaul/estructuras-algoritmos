/*
	Programa que lee una bitácora de accesos, almacena los datos en un grafo
	dirigido (Raíz -> Red -> Host -> Detalles), calcula el grado de salida de
	cada nodo e imprime las redes y los hosts con mayor incidencia.

	Autores:
	- Judith Juquila Lopez Estudillo    A00845789
	- Saul Gabriel Nolasco Cen          A01820888

	Fecha: 21/11/2026
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo {
	string etiqueta;
	vector<int> hijos;
};

/*
- Agrega un nuevo nodo al grafo con su etiqueta y devuelve su índice.
- Complejidad Temporal: O(1)
- Complejidad Espacial: O(1)
*/
int crearNodo(vector<Nodo>& nodos, const string& etiqueta) {
	nodos.push_back({ etiqueta,{} });
	return nodos.size() - 1;
}

/*
- Crea una arista dirigida conectando un nodo origen con un nodo destino.
- Complejidad Temporal: O(1)
- Complejidad Espacial: O(1)
*/
void conectar(vector<Nodo>& nodos, int origen, int destino) {
	nodos[origen].hijos.push_back(destino);
}

/*
- Calcula y devuelve un vector con el grado de salida de cada nodo del grafo.
- Complejidad Temporal: O(V)
- Complejidad Espacial: O(V)
*/
vector<int> calcularGradosSalida(const vector<Nodo>& nodos) {
	vector<int> grados(nodos.size(), 0);
	for (size_t i = 0; i < nodos.size(); i++) {
		grados[i] = nodos[i].hijos.size();
	}
	return grados;
}

int main() {
	vector<Nodo> nodos;
	map<string, int> redes;
	map<string, int> hosts;

	int raiz = crearNodo(nodos, "RAIZ");

	ifstream archivo("bitacora.txt");
	if (!archivo.is_open()) {
		return 1;
	}

	string linea;
	while (getline(archivo, linea)) {
		if (!linea.empty() && linea.back() == '\r') linea.pop_back();
		if (linea.empty()) continue;

		istringstream ss(linea);
		string mes, dia, hora, ipPuerto, mensaje;
		ss >> mes >> dia >> hora >> ipPuerto;
		getline(ss, mensaje);
		if (!mensaje.empty() && mensaje[0] == ' ') mensaje.erase(0, 1);

		string fecha = mes + " " + dia + " " + hora;
		size_t dosPuntos = ipPuerto.find(':');
		string ip = ipPuerto.substr(0, dosPuntos);
		string puerto = ipPuerto.substr(dosPuntos + 1);
		size_t p1 = ip.find('.');
		size_t p2 = ip.find('.', p1 + 1);
		string red = ip.substr(0, p2);

		if (redes.find(red) == redes.end()) {
			int n = crearNodo(nodos, red);
			redes[red] = n;
			conectar(nodos, raiz, n);
		}

		if (hosts.find(ip) == hosts.end()) {
			int n = crearNodo(nodos, ip);
			hosts[ip] = n;
			conectar(nodos, redes[red], n);
		}

		int h = hosts[ip];
		conectar(nodos, h, crearNodo(nodos, puerto));
		conectar(nodos, h, crearNodo(nodos, mensaje));
		conectar(nodos, h, crearNodo(nodos, fecha));
	}
	archivo.close();

	vector<int> grados = calcularGradosSalida(nodos);

	int maxHosts = 0;
	for (const auto& r : redes) {
		maxHosts = max(maxHosts, grados[r.second]);
	}
	for (const auto& r : redes) {
		if (grados[r.second] == maxHosts) {
			cout << r.first << endl;
		}
	}

	cout << endl;

	int maxGradoHost = 0;
	for (const auto& h : hosts) {
		maxGradoHost = max(maxGradoHost, grados[h.second]);
	}
	for (const auto& h : hosts) {
		if (grados[h.second] == maxGradoHost) {
			cout << h.first << endl;
		}
	}

	return 0;
}
