#pragma once

#include "../classes/LinkedList.hpp"

/*
 * Divide la lista en dos mitades usando un puntero rápido (2 saltos) y uno lento (1 salto).
 * Complejidad Temporal: O(N)
 * Complejidad Espacial: O(1)
 */
Node* split(Node* head) {
	Node* fast = head;
	Node* slow = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = nullptr;
	if (temp) temp->prev = nullptr;
	return temp;
}

/*
 * Entrelaza dos sublistas ordenadas conectando sus punteros next y prev in-place (Iterativo).
 * Complejidad Temporal: O(N)
 * Complejidad Espacial: O(1)
 */
Node* merge(Node* first, Node* second) {
	if (!first) return second;
	if (!second) return first;

	Node* head = nullptr;
	Node* tail = nullptr;

	while (first && second) {
		Node* picked;
		if (first->data <= second->data) {
			picked = first;
			first = first->next;
		} else {
			picked = second;
			second = second->next;
		}

		if (!head) {
			head = tail = picked;
			head->prev = nullptr;
		} else {
			tail->next = picked;
			picked->prev = tail;
			tail = picked;
		}
	}

	if (first) {
		tail->next = first;
		first->prev = tail;
	}
	if (second) {
		tail->next = second;
		second->prev = tail;
	}

	return head;
}

/*
 * Divide la lista recursivamente en mitades y luego las une ordenadas usando merge().
 * Complejidad Temporal: O(N log)
 * Complejidad Espacial: O(log N)
 */
Node* mergeSort(Node* head) {
	if (!head || !head->next) return head;
	Node* second = split(head);
	head = mergeSort(head);
	second = mergeSort(second);
	return merge(head, second);
}
