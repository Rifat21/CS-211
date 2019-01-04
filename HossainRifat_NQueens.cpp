// N Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[i] == q[c]) {
			return false;
		}
		if (abs(q[i] - q[c]) == c - i) {
			return false;
		}
	}return true;// Reuse the ok function from your 1D 8 queens program.
}

// This function should return the number of solutions for the given board size.
int nqueens(int n) {
	int* q = new int[n];// Dynamically declare an array of size n and initialize the first element to 0.
	// You don't need to print the solutions.  Just increment a counter each time you find a solution.
	int c = 0;
	int solution=0;
	q[0] = 0;			  // Start in the 1st row, 1st column
	while (c >= 0) {// End the loop if you backtrack from the first column
		if (c == (n-1)) {               // If you are in the last column,
			solution++;                       // Call the print function and backtrack
			c--;
		}
		else {
			c++;
			q[c] = -1;// Otherwise, move to one before the first row of the next column
		}
		while (c >= 0) {
			q[c]++;// Move to the next row
			if (q[c] == n) {
				c--;
			}// If you have passed the end of the column, backtrack
			else if (ok(q, c)) {
				break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
			}
		}
	}
	// Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
	delete[] q;// Delete the array.
	return solution; // Return the number of solutions.
}

int main() {
	int n = 12;
	for (int i = 1; i <= n; ++i)
		cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
	return 0;
}
