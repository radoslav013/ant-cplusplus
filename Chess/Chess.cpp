#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int N = 8;
const char columnIndicators[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const int rowIndicators[] = {8, 7, 6, 5, 4, 3, 2, 1};

struct Direction {
    int operationX;
    int operationY;
};

struct Player {
    char color; // W or B
    string name;
};

void changeColor(int row, int col) {
    HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	if(row == 10 && col == 10) {
        SetConsoleTextAttribute(console_color,
                                FOREGROUND_RED |
                                FOREGROUND_BLUE |
                                FOREGROUND_GREEN); // default
	}else {
        if(row%2==0){
            if(col%2==0){
                SetConsoleTextAttribute(console_color,
                                        BACKGROUND_BLUE |
                                        BACKGROUND_GREEN |
                                        BACKGROUND_RED); // white background, black text
            }else{
                SetConsoleTextAttribute(console_color,
                                FOREGROUND_RED |
                                FOREGROUND_BLUE |
                                FOREGROUND_GREEN); // default
            }
        } else {
            if(col%2==0){
                SetConsoleTextAttribute(console_color,
                                        FOREGROUND_RED |
                                        FOREGROUND_BLUE |
                                        FOREGROUND_GREEN); // default
            }else{
                SetConsoleTextAttribute(console_color,
                                        BACKGROUND_BLUE |
                                        BACKGROUND_GREEN |
                                        BACKGROUND_RED); // white background, black text
            }
        }
	}
}

void printBoard(string board[N][N]){
    cout << "    ";
    for(int coli = 0; coli < N; coli++){
        cout << columnIndicators[coli] << "   ";
    }
    cout << endl;
    for(int row = 0; row < N; row++) {
        cout << rowIndicators[row] << "  ";

        for(int col = 0; col < N; col++) {
            changeColor(row, col);
            cout << board[row][col] << " ";
        }
        changeColor(10, 10);
        cout << " " << rowIndicators[row];
        cout << endl;
    }
    cout << "    ";
    for(int coli = 0; coli < N; coli++){
        cout << columnIndicators[coli] << "   ";
    }
    cout << endl;
}

void printBishopMov(int board[N][N], int x, int y){
    // x to be in the board
    // y to be in the board
    // there should be no figure at this spot.

    // diagonal directions (ne, se, sw, nw)
    const int possibleDir = 4;
    Direction bishopDirection[possibleDir] = {
                            {1, -1}, // ne
                            {1,  1}, // se
                            {-1, 1}, // sw
                            {-1,-1}  // nw
                         };

    for(int i = 0; i < possibleDir; i++){
        int p = x + bishopDirection[i].operationX;
        int q = y + bishopDirection[i].operationY;
        while(p >= 0 && p < N && q >= 0 && q < N && board[q][p] == 0){
            cout << "This position is possible: (" << p << ", " << q << ")" << endl;
            p += bishopDirection[i].operationX;
            q += bishopDirection[i].operationY;
        }
    }
}

void printKnightMov(int board[N][N], int x, int y){
    int possiblePos = 8;
    int possibleX[] = { 2,  1, -1, -2, -2, -1, 1, 2};
    int possibleY[] = {-1, -2, -2, -1,  1 , 2, 2, 1};

    for(int i = 0; i < possiblePos; i++){
        int p = x + possibleX[i]; // 4, 3, 1
        int q = y - possibleY[i]; // 3, 4, 4

        // p to be in the board
        // q to be in the board
        // there should be no figure on this spot
        if(p >= 0 && p < N &&
           q >= 0 && q < N &&
           board[q][p] == 0){
            cout << "This position is possible: (" << p << ", " << q << ")" << endl;
        }
    }

}


void printRookMov(int board[N][N], int x, int y){
    // x to be in the board
    // y to be in the board
    // there should be no figure on this spot and on the way to the spot

    const int possibleDir = 4;
    Direction rookDirection[possibleDir] = {
                            {0, -1}, // n
                            {1,  0}, // e
                            {0,  1}, // s
                            {-1, 0}  // w
                         };

    for(int i = 0; i < possibleDir; i++){
        int p = x + rookDirection[i].operationX;
        int q = y + rookDirection[i].operationY;
        while(p >= 0 && p < N && q >= 0 && q < N && board[q][p] == 0){
            cout << "This position is possible: (" << p << ", " << q << ")" << endl;
            p += rookDirection[i].operationX;
            q += rookDirection[i].operationY;
        }
    }
}

void printQueenMov(int board[N][N], int x, int y){
    // x to be in the board
    // y to be in the board
    // there should be no figure on this spot and on the way to the spot

    const int possibleDir = 8;
    Direction queenDirection[possibleDir] = {
                            {0, -1}, // n
                            {1, -1}, // ne
                            {1,  0}, // e
                            {1,  1}, // se
                            {0,  1}, // s
                            {-1, 1}, // sw
                            {-1, 0}, // w
                            {-1,-1}  // nw
                         };

    for(int i = 0; i < possibleDir; i++){
        int p = x + queenDirection[i].operationX;
        int q = y + queenDirection[i].operationY;
        while(p >= 0 && p < N && q >= 0 && q < N && board[q][p] == 0){
            cout << "This position is possible: (" << p << ", " << q << ")" << endl;
            p += queenDirection[i].operationX;
            q += queenDirection[i].operationY;
        }
    }
}

bool play(string board[N][N], Player currentPlayer){
    // Ask which figure to move.
    // Show all possible position to move this figure.
    // Ask for position.
    // Move the figure.
    // Check for mate and then for checkmate.
    // Return false in case the game continues and true if the game is over.
    return true;
}
int main()
{
    // The player with white figures starts first.
    Player player1;
    player1.color = 'W';
    player1.name = "Nikola";

    Player player2;
    player2.color = 'B';
    player2.name = "Yasin";

    // Abscissa is the horizontal line
    // Ordinate is the vertical line
    string board[N][N] = {
        {"RB1", "HB1", "BB1", "QNB", "KGB", "BB2", "HB2", "RB2"},
        {"PB1", "PB2", "PB3", "PB4", "PB5", "PB6", "PB7", "PB8"},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"PW1", "PW2", "PW3", "PW4", "PW5", "PW6", "PW7", "PW8"},
        {"RW1", "HW1", "BW1", "KGW", "QNW", "BW2", "HW2", "RW2"}
    };
    printBoard(board);
    Player currentPlayer = player1;
    bool isCheckmate = false;
    while(!isCheckmate){
        isCheckmate = play(board, currentPlayer);

        // Change current player.
    }
    /* int kx = 0;
    int ky = 0;
    cout << "Knight: " << endl;
    printKnightMov(board, kx, ky);

    cout << "Bishop: " << endl;
    int bx = 2;
    int by = 1;
    printBishopMov(board, bx, by);

    cout << "Rook: " << endl;
    int rx = 2;
    int ry = 1;
    printRookMov(board, bx, by);

    cout << "Queen: " << endl;
    int qx = 2;
    int qy = 1;
    printQueenMov(board, qx, qy); */

    return 0;
}
/*
Black figures:
PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8
RB1, RB2
HB1, HB2
BB1, BB2
QNB
KGB

For White is the same, just replace B with W
*/
/*
int knightPositionX = 1;
int knightPositionY = 1;
{
    {0, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {1, 1, 0, 1}
}
*/
