#include <iostream>
using namespace std;

char board[3][3]; 

void setupBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}


bool hasWon(char player) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}


bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main() {
    char currentPlayer = 'X';
    int row, col;
    bool gameEnded = false;

    setupBoard();
    cout << "=== Welcome to Tic-Tac-Toe ===\n";

    while (!gameEnded) {
        showBoard();

        cout << "Player " << currentPlayer << ", enter row and column (1 to 3): ";
        cin >> row >> col;

       
        row--; col--;

        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (hasWon(currentPlayer)) {
                showBoard();
                cout << "Congratulations! Player " << currentPlayer << " wins!\n";
                gameEnded = true;
            } else if (isDraw()) {
                showBoard();
                cout << "It's a draw!\n";
                gameEnded = true;
            } else {
              
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Please try again.\n";
        }
    }

    return 0;
}

