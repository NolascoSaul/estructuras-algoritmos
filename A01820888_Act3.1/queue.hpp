#pragma once

template<class T>
class Queue {
private:
	static const int MAX = 1024;
	T data[MAX];
	int frontIdx, endIdx;

public:
	Queue() {
		frontIdx = endIdx = -1;
	}

	void push(T value) {
		if (isFull()) return;

		if (frontIdx == -1) frontIdx = 0;
		endIdx = (endIdx + 1) % MAX;
		data[endIdx] = value;
	}

	T front() {
		if (!isEmpty()) return data[frontIdx];
		return nullptr;
	}

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
