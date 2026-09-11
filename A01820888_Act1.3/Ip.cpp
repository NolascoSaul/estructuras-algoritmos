#include "ip.hpp"
#include <iostream>

Ip::Ip(short firstByte_, short secondByte_, short thirdByte_, short fourthByte_, short port_) :
	firstByte(firstByte_),
	secondByte(secondByte_),
	thirdByte(thirdByte_),
	fourthByte(fourthByte_),
	port(port_) {
}

bool Ip::operator<(const Ip& ipToCompare) const {
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

bool Ip::operator>(const Ip& ipToCompare) const {
	return ipToCompare < *this;
}
