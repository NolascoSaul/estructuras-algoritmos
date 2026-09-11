#pragma once
#include <iostream>

class Ip {
private:
	int firstByte, secondByte, thirdByte, fourthByte;
	int port;

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

	bool operator>(const Ip& ipToCompare) const {
		return ipToCompare < *this;
	}
};
