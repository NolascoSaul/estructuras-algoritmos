#pragma once

#include <iostream>
#include "Log.hpp"

struct Node {
	Log data;
	Node* prev;
	Node* next;
	Node(Log val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
public:
	Node* head;
	Node* tail;

	DoubleLinkedList() : head(nullptr), tail(nullptr) {}

	void append(Log log) {
		Node* newNode = new Node(log);
		if (!head) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	~DoubleLinkedList() {
		Node* current = head;
		while (current) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}
};
