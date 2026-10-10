#pragma once

#include <vector>
#include "../classes/Log.hpp"

int findLowerBound(const vector<Log>& arr, const Date& startDate) {
	int left = 0;
	int right = arr.size() - 1;
	int result = arr.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid].date >= startDate) {
			result = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return result;
}
