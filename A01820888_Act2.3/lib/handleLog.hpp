#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../classes/Log.hpp"
#include "../classes/LinkedList.hpp"

using namespace std;

DoubleLinkedList readLogFile() {
	DoubleLinkedList list;
	ifstream logFile("bitacora.txt");

	string month, time, ipStr, message;
	int day;
	while (logFile >> month >> day >> time >> ipStr) {
		getline(logFile, message);

		if (!message.empty() && message[0] == ' ') {
			message = message.substr(1);
		}

		int hour = stoi(time.substr(0, 2));
		int min = stoi(time.substr(3, 2));
		int sec = stoi(time.substr(6, 2));

		Date date(month, day, hour, min, sec);
		Ip ip(ipStr);

		string dayStr = (day < 10 ? "0" : "") + to_string(day);
		string dateStr = month + " " + dayStr + " " + time;

		Log log(date, ip, dateStr, ipStr, message);

		list.append(log);
	}

	logFile.close();
	return list;
}

void saveSortedLogs(const DoubleLinkedList& list) {
	ofstream outFile("SortedData.txt");

	Node* current = list.head;
	while (current) {
		outFile << current->data.dateStr << " " << current->data.ipStr << " " << current->data.message << "\n";
		current = current->next;
	}

	outFile.close();
}
