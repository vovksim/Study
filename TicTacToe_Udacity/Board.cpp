#include <iostream>
#include "Class&Funcs.h"

using namespace std;

Board ::Board()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gameBoard[i][j] = '-';
        }
    }
}

bool Board ::ValidMove(int row, int column)
{
    if (gameBoard[row][column] != '-')
        return false;
    return true;
}

void Board ::MakeMovePlayerX(int row, int column)
{
    gameBoard[row][column] = 'x';
}

void Board ::MakeMovePlayerO(int row, int column)
{
    gameBoard[row][column] = 'o';
}

void Board ::printBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << '\n';
    }
}

int Board ::checkWin()
{
    // chek rows
    for (int i = 0; i < 4; i++)
    {
        int counter1 = 0, counter2 = 0;
        for (int j = 0; j < 4; j++)
        {
            if (gameBoard[i][j] == 'x')
                counter1++;
            if (gameBoard[i][j] == 'y')
                counter2++;
        }
        if (counter1 == 4)
        {
            return 1;
        }
        if (counter2 == 4)
        {
            return 2;
        }
    }
    // check columns
    for (int i = 0; i < 4; i++)
    {
        int counter1 = 0, counter2 = 0;
        for (int j = 0; j < 4; j++)
        {
            if (gameBoard[j][i] == 'x')
                counter1++;
            if (gameBoard[j][i] == 'y')
                counter2++;
        }
        if (counter1 == 4)
        {
            return 1;
        }
        if (counter2 == 4)
        {
            return 2;
        }
    }
    // check diagonals
    int diagonalcounter1 = 0, diagonalcounter2 = 0;
    for (int i = 0; i < 4; i++)
    {

        if (gameBoard[i][i] == 'x')
            diagonalcounter1++;
        if (gameBoard[i][i] == 'o')
            diagonalcounter2++;
        if (diagonalcounter1 == 4)
        {
            return 1;
        }
        if (diagonalcounter2 == 4)
        {
            return 2;
        }
    }
    diagonalcounter1 = 0, diagonalcounter2 = 0;
    for (int i = 3; i >= 0; i--)
    {
        if (gameBoard[i][3 - i] == 'x')
            diagonalcounter1++;
        if (gameBoard[i][3 - i] == 'o')
            diagonalcounter2++;
        if (diagonalcounter1 == 4)
        {
            return 1;
        }
        if (diagonalcounter2 == 4)
        {
            return 2;
        }
    }
    return 0;
}
