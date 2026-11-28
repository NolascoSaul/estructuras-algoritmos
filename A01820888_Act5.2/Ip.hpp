#pragma once
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Ip {
private:
	int firstByte = 0, secondByte = 0, thirdByte = 0, fourthByte = 0;
	int port = 0;

public:
	Ip(string ipStr) {
		if (ipStr.find(':') == string::npos) {
			sscanf(ipStr.c_str(), "%d.%d.%d.%d", &firstByte, &secondByte, &thirdByte, &fourthByte);
			port = 65535;
		} else {
			sscanf(ipStr.c_str(), "%d.%d.%d.%d:%d", &firstByte, &secondByte, &thirdByte, &fourthByte, &port);
		}
	}

	int getFirstByte() {
		return firstByte;
	}

	int getSecondByte() {
		return secondByte;
	}

	/*
	 * Regresa la red formada por los dos primeros octetos.
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	string getNetwork() {
		return to_string(firstByte) + "." + to_string(secondByte);
	}

	/*
	 * Regresa la dirección IP completa sin puerto y sin ceros a la izquierda.
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	string toString() {
		return to_string(firstByte) + "." + to_string(secondByte) + "." +
			to_string(thirdByte) + "." + to_string(fourthByte);
	}

	bool operator<(const Ip& ipToCompare) {
		if (firstByte != ipToCompare.firstByte)
			return firstByte < ipToCompare.firstByte;

		if (secondByte != ipToCompare.secondByte)
			return secondByte < ipToCompare.secondByte;

		if (thirdByte != ipToCompare.thirdByte)
			return thirdByte < ipToCompare.thirdByte;

		return fourthByte < ipToCompare.fourthByte;
	}

	bool operator==(const Ip& ipToCompare) {
		return firstByte == ipToCompare.firstByte &&
			secondByte == ipToCompare.secondByte &&
			thirdByte == ipToCompare.thirdByte &&
			fourthByte == ipToCompare.fourthByte;
	}

	bool operator!=(const Ip& ipToCompare) {
		return !(*this == ipToCompare);
	}

	bool operator<=(const Ip& ipToCompare) {
		return *this < ipToCompare || *this == ipToCompare;
	}

	bool operator>=(const Ip& ipToCompare) {
		return !(*this < ipToCompare);
	}
};
