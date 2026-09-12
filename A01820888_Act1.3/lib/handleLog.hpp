#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "../classes/Log.hpp"

using namespace std;

vector<Log> readLogFile() {
	vector<Log> logs;
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
		string dateStr = month + " " + to_string(day) + " " + time;

		Log log(date, ip, dateStr, ipStr, message);

		logs.push_back(log);
	}

	logFile.close();
	return logs;
}
