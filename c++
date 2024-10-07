#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChessPiece {
public:
    virtual char getSymbol() const = 0;
};

class Pawn : public ChessPiece {
public:
    char getSymbol() const override {
        return 'P';
    }
};

class Rook : public ChessPiece {
public:
    char getSymbol() const override {
        return 'R';
    }
};

class Knight : public ChessPiece {
public:
    char getSymbol() const override {
        return 'N';
    }
};

class Bishop : public ChessPiece {
public:
    char getSymbol() const override {
        return 'B';
    }
};

class Queen : public ChessPiece {
public:
    char getSymbol() const override {
        return 'Q';
    }
};

class King : public ChessPiece {
public:
    char getSymbol() const override {
        return 'K';
    }
};

class Board {
private:
    vector<vector<ChessPiece*> > grid;

public:
    Board() {
        grid.resize(8, vector<ChessPiece*>(8, nullptr));
        setupBoard();
    }

    ~Board() {
        for (auto& row : grid) {
            for (auto& piece : row) {
                delete piece;
            }
        }
    }

    void setupBoard() {
        // Set up Pawns
        for (int i = 0; i < 8; ++i) {
            grid[1][i] = new Pawn(); // White Pawns
            grid[6][i] = new Pawn(); // Black Pawns
        }

        // Set up Rooks
        grid[0][0] = new Rook();   grid[0][7] = new Rook();   // White Rooks
        grid[7][0] = new Rook();   grid[7][7] = new Rook();   // Black Rooks

        // Set up Knights
        grid[0][1] = new Knight(); grid[0][6] = new Knight(); // White Knights
        grid[7][1] = new Knight(); grid[7][6] = new Knight(); // Black Knights

        // Set up Bishops
        grid[0][2] = new Bishop(); grid[0][5] = new Bishop(); // White Bishops
        grid[7][2] = new Bishop(); grid[7][5] = new Bishop(); // Black Bishops

        // Set up Queens and Kings
        grid[0][3] = new Queen();  grid[0][4] = new King();   // White Queen and King
        grid[7][3] = new Queen();  grid[7][4] = new King();   // Black Queen and King
    }

    void printBoard() const {
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                if (grid[i][j]) {
                    cout << grid[i][j]->getSymbol() << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Board chessBoard;
    chessBoard.printBoard();

    // Main game loop can be implemented here.
    // You can add functionality to move pieces, check for valid moves, etc.

    return 0;
}
