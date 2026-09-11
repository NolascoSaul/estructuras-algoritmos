#pragma once
#include <iostream>

class Ip {
private:
	short firstByte, secondByte, thirdByte, fourthByte;
	short port;

public:
	Ip(short firstByte_, short secondByte_, short thirdByte_, short fourthByte_, short port_);

	bool operator<(const Ip& ipToCompare) const;
	bool operator>(const Ip& ipToCompare) const;
};
