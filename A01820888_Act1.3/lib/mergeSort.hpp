#pragma once

#include <vector>
#include "../classes/Log.hpp"

using namespace std;

void merge(vector<Log>& arr, int start, int mid, int end) {
	int sizeL = mid - start + 1;
	int sizeR = end - mid;

	vector<Log> left(arr.begin() + start, arr.begin() + mid + 1);
	vector<Log> right(arr.begin() + mid + 1, arr.begin() + end + 1);

	int i = 0;
	int j = 0;
	int k = start;

	while (i < sizeL && j < sizeR) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while (i < sizeL)
		arr[k++] = left[i++];

	while (j < sizeR)
		arr[k++] = right[j++];
}

void mergeSort(vector<Log>& arr, int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
