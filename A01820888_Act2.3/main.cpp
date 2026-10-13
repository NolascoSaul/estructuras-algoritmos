/*
	Programa que lee los registros del archivo bitacora.txt, los ordena por IP de manera descendente mediante
	Merge Sort, guarda el resultado en SortedData.txt y muestra los registros comprendidos
	entre los IP proporcionadas por el usuario.

	Integrantes:
	- Saúl Gabriel Nolasco Cen - A01820888
	- Judith Juquila Lopez Estudillo - A00845789

	Fecha de creacion: 09/10/2026
*/

#include <iostream>
#include "lib/handleLog.hpp"
#include "lib/mergeSort.hpp"
#include "lib/searchNode.hpp"
#include "classes/Log.hpp"
#include "classes/LinkedList.hpp"

using namespace std;

int main() {
	DoubleLinkedList list = readLogFile();

	list.head = mergeSort(list.head);

	Node* temp = list.head;
	while (temp && temp->next) {
		temp = temp->next;
	}
	list.tail = temp;

	saveSortedLogs(list);

	string startIpStr, endIpStr;
	cin >> startIpStr;
	cin >> endIpStr;

	Ip startIp(startIpStr);
	Ip endIp(endIpStr);

	Node* current = findUpperBoundNode(list.head, endIp);

	while (current != nullptr && current->data.ip >= startIp) {
		cout << current->data.dateStr << " " << current->data.ipStr << " " << current->data.message << "\n";
		current = current->prev;
	}

	return 0;
}
