#pragma once
#include <iostream>

class Ip {
private:
	int firstByte = 0, secondByte = 0, thirdByte = 0, fourthByte = 0;
	int port = 0;

public:
	Ip(string ipStr) {
		sscanf(
			ipStr.c_str(),
			"%d.%d.%d.%d:%d",
			&firstByte, &secondByte, &thirdByte, &fourthByte, &port
		);
	}

	bool operator<(const Ip& ipToCompare) const {
		if (firstByte != ipToCompare.firstByte)
			return firstByte < ipToCompare.firstByte;

		if (secondByte != ipToCompare.secondByte)
			return secondByte < ipToCompare.secondByte;

		if (thirdByte != ipToCompare.thirdByte)
			return thirdByte < ipToCompare.thirdByte;

		if (fourthByte != ipToCompare.fourthByte)
			return fourthByte < ipToCompare.fourthByte;

		return port < ipToCompare.port;
	}

	bool operator==(const Ip& ipToCompare) const {
		if (firstByte != ipToCompare.firstByte)
			return false;

		if (secondByte != ipToCompare.secondByte)
			return false;

		if (thirdByte != ipToCompare.thirdByte)
			return false;

		if (fourthByte != ipToCompare.fourthByte)
			return false;

		return port == ipToCompare.port;
	}

	bool operator!=(const Ip& ipToCompare) const {
		return !(*this == ipToCompare);
	}

	bool operator<=(const Ip& ipToCompare) const {
		return *this < ipToCompare || *this == ipToCompare;
	}

	bool operator>=(const Ip& ipToCompare) const {
		return !(*this < ipToCompare);
	}
};
