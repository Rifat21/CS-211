// Score The Race.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std; 

int main() {
	while (true) {
		string outcome;
		bool ok = true;
		cout << "Enter the race outcome: ";
		cin >> outcome;
		if (outcome == "done") {
			return false;
		}// If the user entered "done", exit the program
		int numTeams = 0;       // The number of teams
		int scores['Z' + 1] = {}; // scores[i] keeps track of the total score of team i
		int counts['Z' + 1] = {}; // counts[i] keeps track of the number of runners on team i
		for (int i = 0; i < outcome.length(); i++) { // For each runner in the race,
			scores[outcome[i]] += i + 1;									 // Increase the team's score by the runner's rank (the rank is 1 more than the index)
			if (counts[outcome[i]] == 0) numTeams++;									 // If it's the first runner of that particular team, update the total number of teams
			counts[outcome[i]] ++;										 // Update the number of runners on the team
		}
		for (int i = 65; i < 91; i++) {// If the teams do not all have the same number of runners,
			if (counts[i] !=0 && (counts[i] / counts[outcome[0]]) != 1) {
				cout << "The teams don't have the same number of runners." << endl;
				ok = false;
				break;
			}
		}// Print an error message and ask for input again (go back to the beginning of the loop)
		if (ok == true) { 
			double bestScore = (double)scores[outcome[0]] / counts[outcome[0]];
			double temp;
			int team = outcome[0];
			cout << "There are " << numTeams << " teams" << endl; // Print the number of teams
			cout << "Each team has " << counts[outcome[0]] << " runners." << endl;// Print the number of runners on each team
			for (int i = 65; i < 91; i++) {  // For each letter from A-Z,
				if (scores[i] != 0) {  // If that team participated,
					temp = (double)scores[i] / counts[i];  // Print the name of the team and its average score
					cout << (char)i << ": " << temp << endl;   // Also keep track of which team(s) has the best score
					if (temp < bestScore) {
						bestScore = temp;
						team = i;
					}
				}
			}
			cout << "The winning team is team " << (char)team << " with score " << bestScore << "." << endl;
		}// Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
	}
	return 0;
}