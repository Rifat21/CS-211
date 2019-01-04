// 8Queens1DWithoutGoTo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[i] == q[c]) {
			return false;
		}
		if (abs(q[i] - q[c]) == c - i) {
			return false;
		}
	}return true;
}

void print(int q[]) {
	static int numSolutions = 0;
	cout << "Solution #" << ++numSolutions << ": ";
	for (int i = 0; i < 8; i++) {
		cout << q[i];// Print the array
	}
	cout << "\n";
}

int main() {
	int q[8] = {}, c = 0;   // Initialize the array to 0.
	q[0] = 0;			  // Start in the 1st row, 1st column

	while (c >= 0) {// End the loop if you backtrack from the first column
		if (c == 7) {               // If you are in the last column,
			print(q);                       // Call the print function and backtrack
			c--;
		}
		else {
			c++;
			q[c] = -1;// Otherwise, move to one before the first row of the next column
		}
		while (c >= 0) {
			q[c]++;// Move to the next row
			if (q[c] == 8) {
				c--;
			}// If you have passed the end of the column, backtrack
			else if (ok(q, c)) {
				break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
			}
		}
	}
	return 0;
}