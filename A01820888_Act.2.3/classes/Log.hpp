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

	bool operator<=(const Log& logToCompare) const {
		if (date != logToCompare.date)
			return date < logToCompare.date;

		if (ip < logToCompare.ip)
			return ip < logToCompare.ip;

		return message < logToCompare.message;
	}
};
