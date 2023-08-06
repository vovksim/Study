#include "AdditionalFuncs.h"
#include <iostream>
#include <string>

using namespace std;

void NamePlayers(string& player1, string& player2) {
	cout << "PlayerX! Enter your name: " << '\n';
	cin >> player1;
	cout << "PlayerO! Enter your name: " << '\n';
	cin >> player2;
}

vector<int> convertInputToRowsAndColumns(int position) {
	int counter = 0;
	vector<int> a;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			counter++;
			if (counter == position) {
				a.push_back(i);
				a.push_back(j);
			}
		}
	}
	return a;
}