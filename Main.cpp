#include <iostream>
using namespace std;

class Board {
private:
    char grid[3][3];

public:
    Board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
    }

    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--|---|--" << endl;
        }
    }

    bool placeMark(int row, int col, char mark) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || grid[row][col] != ' ') {
            return false;
        }
        grid[row][col] = mark;
        return true;
    }

    char checkWin() {
        // перевірте рядки
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
                return grid[i][0];
            }
        }

        // перевірте стовпці
        for (int i = 0; i < 3; i++) {
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
                return grid[0][i];
            }
        }

        // перевірте діагоналі
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
            return grid[0][0];
        }
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
            return grid[0][2];
        }

        return ' '; // якщо ніхто не виграв
    }

    bool isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

class Game {
private:
    Board board;
    char currentPlayer;

public:
    Game() : currentPlayer('X') {}

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        bool moveValid;
        char winner;

        while (true) {
            board.display();

            cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
            cin >> row >> col;

            .placeMark(row, col, currentPlayer);

            if (!moveValid) {
                ;
                continue;
            }

            winner = board.checkWin();

            if (winner != ' ') {
                board.display();
                cout << "Player " << winner << " wins!" << endl;
                break;
            }

            if (board.isFull()) {
                board.display();
                cout << "It's a draw!" << endl;
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}