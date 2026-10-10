/*
	Programa que...

	Autores:
	- David Medel de la Trinidad	A01821075
	- Erika Danae Arroyo Silva		A01820835
	- Saul Gabriel Nolasco Cen		A01820888

	Fecha: 12/09/2026
*/

#include <iostream>
#include "lib/handleLog.hpp"
#include "lib/mergeSort.hpp"
#include "lib/binarySearch.hpp"
#include "classes/Log.hpp"

using namespace std;

int main() {
	vector<Log> logs = readLogFile();

	mergeSort(logs, 0, logs.size() - 1);
	saveSortedLogs(logs);

	int startMonth, startDay;
	int endMonth, endDay;
	cin >> startMonth >> startDay;
	cin >> endMonth >> endDay;

	Date startDate(startMonth, startDay, 0, 0, 0);
	Date endDate(endMonth, endDay, 23, 59, 59);

	int startIndex = findLowerBound(logs, startDate);
	for (int i = startIndex; i < logs.size(); i++) {
		if (endDate < logs[i].date) break;

		cout << logs[i].dateStr << " " << logs[i].ipStr << " " << logs[i].message << endl;
	}

	return 0;
}
