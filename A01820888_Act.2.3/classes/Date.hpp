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
		month = monthToNumber(monthStr_);
	}

	Date(int month_, int day_, int hour_, int min_, int sec_)
		: month(month_), day(day_), hour(hour_), min(min_), sec(sec_) {
		monthStr = numToMonthStr(month_);
	}

	int monthToNumber(string monthString) {
		if (monthString == "Jan") return 1;
		else if (monthString == "Feb") return 2;
		else if (monthString == "Mar") return 3;
		else if (monthString == "Apr") return 4;
		else if (monthString == "May") return 5;
		else if (monthString == "Jun") return 6;
		else if (monthString == "Jul") return 7;
		else if (monthString == "Aug") return 8;
		else if (monthString == "Sep") return 9;
		else if (monthString == "Oct") return 10;
		else if (monthString == "Nov") return 11;
		else if (monthString == "Dec") return 12;

		return 0;
	}

	string numToMonthStr(int monthNum) {
		const string months[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
										"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		if (monthNum >= 1 && monthNum <= 12) return months[monthNum];
		return "Jan";
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

	bool operator>=(const Date& dateToCompare) const {
		return !(*this < dateToCompare);
	}

	bool operator!=(const Date& dateToCompare) const {
		return !(*this == dateToCompare);
	}
};
