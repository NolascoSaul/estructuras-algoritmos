#include <iostream>
#include "ip.hpp"
using namespace std;

int main() {
	Ip ip1(233, 99, 27, 158, 6526);
	Ip ip2(236, 101, 82, 67, 4342);

	cout << (ip1 < ip2) << endl;
	cout << (ip1 > ip2) << endl;

	return 0;
}
