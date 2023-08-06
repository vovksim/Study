class Board {
    char gameBoard[4][4];
public:
    Board();
    bool ValidMove(int row, int column);
    void MakeMovePlayerX(int row, int column);
    void MakeMovePlayerO(int row, int column);
    void printBoard();
    int checkWin();
};