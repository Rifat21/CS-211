// Shortest Path Non-Recursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int minRow, minLength;
const int rows = 5, cols = 6;
string path[rows][cols];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
	static int weight[rows][cols] = {
	{ 3,4,1,2,8,6 },
	{ 6,1,8,2,7,4 },
	{ 5,9,3,9,9,5 },
	{ 8,4,1,3,2,6 },
	{ 3,7,2,8,6,4 } };
	// Declare the cost matrix.
	static int cost[rows][cols] = { 0 };
	// Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
	int up, left, down, minCost;
	for (int i = 0; i < rows; i++) {
		cost[i][0] = weight[i][0];
		path[i][0] = to_string(i);
	}
	for (int j = 1; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			if (i == 0) {
				up = cost[4][j - 1] + weight[i][j];
				left = cost[i][j - 1] + weight[i][j];
				down = cost[i + 1][j - 1] + weight[i][j];
				minCost = min(up, min(left, down));
				cost[i][j] = minCost;
				if (minCost == up) {
					if (i == 0) {
						path[i][j] = path[4][j - 1] + to_string(i);
					}
					else path[i][j] = path[i - 1][j - 1] + to_string(i);
				}
				// If left is the minimum...
				else if (minCost == left) {
					path[i][j] = path[i][j - 1] + to_string(i);
				}
				// If down is the minimum...
				else if (minCost == down) {
					if (i == 4) {
						path[i][j] = path[0][j - 1] + to_string(i);
					}
					else path[i][j] = path[i + 1][j - 1] + to_string(i);
				}
			}
			else if (i == 4) {
				up = cost[i - 1][j - 1] + weight[i][j];
				left = cost[i][j - 1] + weight[i][j];
				down = cost[0][j - 1] + weight[i][j];
				minCost = min(up, min(left, down));
				cost[i][j] = minCost;
				if (minCost == up) {
					if (i == 0) {
						path[i][j] = path[4][j - 1] + to_string(i);
					}
					else path[i][j] = path[i - 1][j - 1] + to_string(i);
				}
				// If left is the minimum...
				else if (minCost == left) {
					path[i][j] = path[i][j - 1] + to_string(i);
				}
				// If down is the minimum...
				else if (minCost == down) {
					if (i == 4) {
						path[i][j] = path[0][j - 1] + to_string(i);
					}
					else path[i][j] = path[i + 1][j - 1] + to_string(i);
				}
			}
			else {
				up = cost[i - 1][j - 1] + weight[i][j];
				left = cost[i][j - 1] + weight[i][j];
				down = cost[i + 1][j - 1] + weight[i][j];
				minCost = min(up, min(left, down));
				cost[i][j] = minCost;
				if (minCost == up) {
					if (i == 0) {
						path[i][j] = path[4][j - 1] + to_string(i);
					}
					else path[i][j] = path[i - 1][j - 1] + to_string(i);
				}
				// If left is the minimum...
				else if (minCost == left) {
					path[i][j] = path[i][j - 1] + to_string(i);
				}
				// If down is the minimum...
				else if (minCost == down) {
					if (i == 4) {
						path[i][j] = path[0][j - 1] + to_string(i);
					}
					else path[i][j] = path[i + 1][j - 1] + to_string(i);
				}
			}
		}
		// For each remaining column,
		// Calculate the cost of each square in the column (non-recursively),
		// and store the correct number in the cost matrix and the correct string in the path matrix.
		// Check which square in the rightmost column has the lowest cost.  Store that cost in minLength and the row number in minRow.
		minRow = 0;
		minLength = cost[0][cols - 1];
		for (int i = 0; i < rows; i++) {
			if (cost[i][cols - 1] < minLength) {
				minRow = i;
				minLength = cost[i][cols - 1];
			}
		}
	}
}

int main() {
	calculateCosts();
	cout << "The length of the shortest path is " << minLength;
	cout << ".\nThe rows of the path from left to right are " << path[minRow][cols - 1] << ".";

	return 0;
}