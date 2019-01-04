// Stable Marriage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

static int mp[3][3] = { { 0,2,1 },  // Man#0's preferences
{ 0,2,1 },  // Man#1's preferences
{ 1,2,0 } }; // Man#2's preferences

static int wp[3][3] = { { 2,1,0 },  // Woman#0's preferences
{ 0,1,2 },  // Woman#1's preferences
{ 2,0,1 } }; // Woman#2's preferences

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[i] == q[c]) {
			return false;
		}
		if ((mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < mp[q[c]][c]) || (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])){
			return false;
		}
	}return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; ++i)
		cout << i << "\t" << q[i] << "\n";
	cout << "\n";
}

int main() {

	int q[3] = {}, c = 0;   // Initialize the array to 0.
	q[0] = 0;			  // Start in the 1st row, 1st column

	while (c >= 0) {// End the loop if you backtrack from the first column
		if (c == 2) {               // If you are in the last column,
			print(q);                       // Call the print function and backtrack
			c--;
		}
		else {
			c++;
			q[c] = -1;// Otherwise, move to one before the first row of the next column
		}
		while (c >= 0) {
			q[c]++;// Move to the next row
			if (q[c] == 3) {
				c--;
			}// If you have passed the end of the column, backtrack
			else if (ok(q, c)) {
				break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
			}
		}
	}
	return 0;
}