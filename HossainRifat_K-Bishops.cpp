// K-Bishop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
	for (int i = 0; i < c; i++) {
		if (abs((q[i] / n )- (q[c] / n)) == (abs((q[i] % n) - (q[c] % n)))) {
			return false;
		}
	}return true;// Fill in.  You will probably want to add n as a 3rd parameter.
}

// The function below is from a working n queens program.
// Add a 2nd parameter, k, and modify the function so that it will work for the k bishops program.
// You will have to change the board representation, the condition for when you've found a solution, and when to backtrack.
int kbishops(int n, int k) {
	int* q = new int[k];
	q[0] = 0;
	int c = 0, solutions = 0;
	while (c >= 0) {
		++c;
		if (c == k) {
			++solutions;
			--c;
		}
		else
			q[c] = q[c-1];
		while (c >= 0) {
			++q[c];
			if (q[c] == (n*n))
				--c;
			else if (ok(q, c, n))
				break;
		}
	}
	delete[] q;
	return solutions;
}

int main() {
	int n, k;
	while (true) {
		cout << "Enter value of n: ";
		cin >> n;
		if (n == -1)
			break;
		cout << "Enter value of k: ";
		cin >> k;
		cout << "number of solutions: " << kbishops(n, k) << "\n";
	}
	return 0;
}