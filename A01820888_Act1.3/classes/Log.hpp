#pragma once

#include <iostream>
#include "Date.hpp"
#include "Ip.hpp"
using namespace std;

struct Log {
	Date date;
	Ip ip;
	string dateStr, ipStr, message;

	Log(Date date_, Ip ip_, string dateStr_, string ipStr_, string message_)
		: date(date_), ip(ip_), dateStr(dateStr_), ipStr(ipStr_), message(message_) {
	}

	bool operator<(const Log& other) const {
		if (date < other.date) return true;
		if (other.date < date) return false;

		return ip < other.ip;
	}

	bool operator<=(const Log& other) const {
		return !(other < *this);
	}
};
