#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
	BinSearchTree bst;
	int val;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		bst.insert(val);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> val;
		bst.erase(val);
	}

	bst.traversal(1);
	bst.traversal(2);
	bst.traversal(3);
	bst.traversal(4);

	cout << bst.height(bst.root) << endl;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> val;
		bst.ancestors(val);
	}

	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		cin >> val;
		cout << bst.whatlevelamI(val) << endl;
	}

	return 0;
}
