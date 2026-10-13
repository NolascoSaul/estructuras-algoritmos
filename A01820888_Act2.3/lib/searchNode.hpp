#pragma once
#include "../classes/LinkedList.hpp"

/*
 * Búsqueda secuencial del límite superior. Avanza hasta encontrar la última IP que cumpla el rango.
 * Complejidad Temporal: O(N)
 * Complejidad Espacial: O(1)
 */
Node* findUpperBoundNode(Node* head, const Ip& endIp) {
	Node* current = head;
	Node* lastMatch = nullptr;

	while (current != nullptr && current->data.ip <= endIp) {
		lastMatch = current;
		current = current->next;
	}
	return lastMatch;
}
