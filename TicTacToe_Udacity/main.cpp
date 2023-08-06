#include "AdditionalFuncs.h"
#include "Class&Funcs.h"

using namespace std;



int main() {
	string playerX, playerO;
	int winner = 0, moves = 0;
	int position;
	Board TicTacToe;
	NamePlayers(playerX, playerO);
	do {
		TicTacToe.printBoard();
		if (winner != 2 or winner!=1) {
			if (moves % 2 == 0) {
				cout << playerX << " make your move!" << endl;
				cin >> position;
				vector<int> coordinates = convertInputToRowsAndColumns(position);
				int row = coordinates[0], column = coordinates[1];
				if (TicTacToe.ValidMove(row, column)) {
					TicTacToe.MakeMovePlayerX(row, column);
				}
				else {
					cout << "Invalid value!" << endl;
					break;
				}
			}
			else {
				cout << playerO << " make your move!" << endl;
				cin >> position;
				vector<int> coordinates = convertInputToRowsAndColumns(position);
				int row = coordinates[0], column = coordinates[1];
				if (TicTacToe.ValidMove(row, column)) {
					TicTacToe.MakeMovePlayerX(row, column);
				}
				else {
					cout << "Invalid value!" << endl;
					break;
				}
				TicTacToe.MakeMovePlayerO(row, column);
			}
			winner = TicTacToe.checkWin();
			if (winner == 2) {
				cout << playerO << " wins! Congrats!" << endl;
				break;
			}
			else if (winner == 1) {
				cout << playerX << " wins! Congrats!" << endl;
				break;
			}
			moves++;
		}
	} while (moves<16);
	TicTacToe.printBoard();
	if (winner == 0 and moves == 16) {
		cout << "Tie!" << endl;
	}
	return 0;
}