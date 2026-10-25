#pragma once

template<class T>
class Queue {
private:
	static const int MAX = 2048;
	T data[MAX];
	int frontIdx, endIdx;

public:
	Queue() {
		frontIdx = endIdx = -1;
	}

	/*
	- Inserta un elemento al final de la cola usando el residuo para hacerla circular.
	- Complejidad Temporal: O(1)
	- Complejidad Espacial: O(1)
	*/
	void push(T value) {
		if (isFull()) return;

		if (frontIdx == -1) frontIdx = 0;
		endIdx = (endIdx + 1) % MAX;
		data[endIdx] = value;
	}

	/*
	- Devuelve el valor del frente sin sacarlo de la estructura.
	- Complejidad Temporal: O(1)
	- Complejidad Espacial: O(1)
	*/
	T front() {
		if (!isEmpty()) return data[frontIdx];
		return nullptr;
	}

	/*
	- Extrae y devuelve el elemento del frente, moviendo el índice de inicio.
	- Complejidad Temporal: O(1)
	- Complejidad Espacial: O(1)
	*/
	T pop() {
		T value = data[frontIdx];
		if (frontIdx == endIdx)
			frontIdx = endIdx = -1;
		else
			frontIdx = (frontIdx + 1) % MAX;

		return value;
	}

	bool isEmpty() {
		return frontIdx == -1;
	}

	bool isFull() {
		if (isEmpty()) return false;
		return (endIdx + 1) % MAX == frontIdx;
	}
};
