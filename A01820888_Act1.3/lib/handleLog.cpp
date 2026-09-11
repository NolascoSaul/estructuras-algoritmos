#include <iostream>
#include <vector>
#include <fstream>
#include "../classes/Register.hpp"

using namespace std;

vector<Register> readLogFile() {
	vector<Register> registers;
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

		Register reg(date, ip, dateStr, ipStr, message);

		registers.push_back(reg);
	}

	logFile.close();
	return registers;
}
