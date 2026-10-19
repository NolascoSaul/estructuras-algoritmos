#pragma once

template<class T>
struct QNode {
	T data;
	QNode* next;
	QNode(T val) : data(val), next(nullptr) {}
};

template<class T>
class Queue {
private:
	QNode<T>* head;
	QNode<T>* tail;

public:
	Queue() {
		head = nullptr;
		tail = nullptr;
	}

	~Queue() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(T value) {
		QNode<T>* newNode = new QNode<T>(value);
		if (isEmpty()) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	T front() {
		if (!isEmpty()) return head->data;
		return nullptr;
	}

	T pop() {
		if (isEmpty()) return nullptr;

		QNode<T>* temp = head;
		T value = temp->data;

		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}

		delete temp;
		return value;
	}

	bool isEmpty() {
		return head == nullptr;
	}
};
