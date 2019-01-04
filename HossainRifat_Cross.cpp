// Cross.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
	static int adj[8][5] = {
		{-1},
		{0,-1},
		{0,1,-1},
		{0,2,-1},
		{1,2,-1},
		{1,2,3,4,-1},
		{2,3,5,-1},
		{4,5,6,-1},
	};

	for (int i = 0; i < c; i++) {
		if (q[i] == q[c]) {
			return false;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (adj[c][i] == -1) 
		{ 
			break; 
		}
		else if (abs(q[adj[c][i]] - q[c]) == 1) {
			return false;
		}
	}
	return true;
}

void print(int q[]) {
	static int numSolutions = 0;
	cout << "Solution #" << ++numSolutions << ": " << endl;
	cout << " " << q[1] << q[4];
	cout << endl << q[0] << q[2] << q[5] << q[7]<< endl;
	cout << " " << q[3] << q[6] << endl;
	cout << "\n";
}

int main() {
	int q[8] = {}, c = 0;   // Initialize the array to 0.
	q[0] = 1;			  // Start in the 1st row, 1st column

	while (c >= 0) {// End the loop if you backtrack from the first column
		if (c == 7) {               // If you are in the last column,
			print(q);                       // Call the print function and backtrack
			c--;
		}
		else {
			c++;
			q[c] = 0;// Otherwise, move to one before the first row of the next column
		}
		while (c >= 0) {
			q[c]++;// Move to the next row
			if (q[c] == 9) {
				c--;
			}// If you have passed the end of the column, backtrack
			else if (ok(q, c)) {
				break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
			}
		}
	}
	return 0;
}