#pragma once

#include <iostream>
using namespace std;

class Date {
private:
	string monthStr;
	int month, day, hour, min, sec;

public:
	Date(string monthStr_, int day_, int hour_, int min_, int sec_) :
		monthStr(monthStr_), day(day_), hour(hour_), min(min_), sec(sec_) {
		monthToNumber(monthStr);
	}

	void monthToNumber(string monthString) {
		if (monthString == "Jan") month = 1;
		else if (monthString == "Feb") month = 2;
		else if (monthString == "Mar") month = 3;
		else if (monthString == "Apr") month = 4;
		else if (monthString == "May") month = 5;
		else if (monthString == "Jun") month = 6;
		else if (monthString == "Jul") month = 7;
		else if (monthString == "Aug") month = 8;
		else if (monthString == "Sep") month = 9;
		else if (monthString == "Oct") month = 10;
		else if (monthString == "Nov") month = 11;
		else if (monthString == "Dec") month = 12;
		else month = 0;
	}

	bool operator<(const Date& dateToCompare) const {
		if (month != dateToCompare.month)
			return month < dateToCompare.month;

		if (day != dateToCompare.day)
			return day < dateToCompare.day;

		if (hour != dateToCompare.hour)
			return hour < dateToCompare.hour;

		if (min != dateToCompare.min)
			return min < dateToCompare.min;

		return sec < dateToCompare.sec;
	}

	bool operator==(const Date& dateToCompare) const {
		if (month != dateToCompare.month)
			return false;

		if (day != dateToCompare.day)
			return false;

		if (hour != dateToCompare.hour)
			return false;

		if (min != dateToCompare.min)
			return false;

		return sec == dateToCompare.sec;
	}

	bool operator!=(const Date& dateToCompare) const {
		return !(*this == dateToCompare);
	}
};
