// Shortest Path Recursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
string path[rows][cols];

// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
	static int weight[rows][cols] = { 
	{ 3,4,1,2,8,6 },
	{ 6,1,8,2,7,4 },
	{ 5,9,3,9,9,5 },
	{ 8,4,1,3,2,6 },
	{ 3,7,2,8,6,4 } };
	// Declare the cost matrix.
	static int cost[rows][cols] = {0};
	// If the cost has already been calculated, return it.
	if (cost[i][j] != 0) {
		return cost[i][j];
	}
	// Check for the base case.
	if (j == 0) {
		path[i][j] = to_string(i);
		return weight[i][j];
	}

	// Calculate the costs of the 3 adjacent squares by calling the function recursively.
	int up, down, left;
	if (i == 0) {
		up = calculateCost(4, j - 1);
		left = calculateCost(i, j - 1);
		down = calculateCost(i + 1, j - 1);
	}
	else if (i == 4) {
		up = calculateCost(i - 1, j - 1);
		left = calculateCost(i, j - 1);
		down = calculateCost(0, j - 1);
	}
	else {
		up = calculateCost(i - 1, j - 1);
		left = calculateCost(i, j - 1);
		down = calculateCost(i + 1, j - 1);
	}

	// Find the minimum of the 3 costs.
	int minCost = min(up, min(left, down));
	// Update the path matrix (store the path to the current square in path[i][j]):
	// If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
	if (minCost == up) {
		if (i == 0) {
			path[i][j] = path[4][j - 1] + to_string(i);
		}
		else path[i][j] = path[i-1][j-1] + to_string(i);
	}
	// If left is the minimum...
	else if (minCost == left) {
		path[i][j] = path[i][j-1] + to_string(i);
	}
	// If down is the minimum...
	else if (minCost == down) {
		if(i==4){ 
			path[i][j] = path[0][j - 1] + to_string(i); 
		}
		else path[i][j] = path[i+1][j-1] + to_string(i);
	}
	// Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
	cost[i][j] = minCost + weight[i][j];
	return cost[i][j];
}

int main() {
	int minRow = 0;
	// Call the calculateCost function once for each square in the rightmost column of the grid.
	for (int i = 0; i < rows; i++) {
		calculateCost(i, cols-1);
		if (calculateCost(i, 0) < calculateCost(minRow, cols-1)) {
			minRow = i;
		}
	}
	// Check which one has the lowest cost and store the row number in minRow.

	cout << "The length of the shortest path is " << calculateCost(minRow, cols-1);
	cout << ".\nThe rows of the path from left to right are " << path[minRow][cols - 1] << ".";

	return 0;
}