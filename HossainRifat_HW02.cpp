
#include "stdafx.h"
#include <iostream>
using namespace std;

// You may use an additional helper function if you want
bool same(int a[], int b[], int n, int shift) {
	for (int i = 0; i < n; i++) {
		if (a[(i + shift) % n] != b[i])
		{
			return false;
		}
	}return true;
}

bool equivalent(int a[], int b[], int n) {
	bool equiv = false;
	int shift = 0;

	for (int shift = 0; shift < n; shift++) {
		equiv = same(a, b, n, shift);
		if (equiv == true)
		{
			return true;
		}
	}return false;
}


int main() {
	cout << boolalpha; // to print bool values as true/false instead of 1/0

	int a1[5] = { 1, 2, 3, 4, 5 };
	int a2[5] = { 3, 4, 5, 1, 2 };
	cout << equivalent(a1, a2, 5) << endl; // true

	int b1[3] = { 1, 2, 3 };
	int b2[3] = { 2, 3, 3 };
	cout << equivalent(b1, b2, 3) << endl; // false

	int c1[4] = { 2, 3, 4, 1 };
	int c2[4] = { 1, 4, 3, 2 };
	cout << equivalent(c1, c2, 4) << endl; // false

	int d1[4] = { 3, 2, 3, 1 };
	int d2[4] = { 3, 1, 3, 2 };
	cout << equivalent(d1, d2, 4) << endl; // true

	int e1[5] = { 1, 1, 1, 1, 2 };
	int e2[5] = { 1, 1, 1, 2, 1 };
	cout << equivalent(e1, e2, 5) << endl; // true

	return 0;
}