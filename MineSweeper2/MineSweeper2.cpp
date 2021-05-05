#include <iostream>
#include <time.h>

using namespace std;

/*
* BEGINNER 10x10 10 mines
* INTERMEDIATE 14x14 40 mines
* ADVANCED 25x25 99 mines
*/

// TODO 1: Make custom difficulty level (n x m) and mines < (n*m)
// TODO 2: Try to implement the minesBoard array as 1-dimensional and store (row, col) for every mine.

struct Mine {
    int row;
    int col;
};

const int BEGINNER_MINES = 10;
const int INTERMADIATE_MINES = 40;
const int ADVANCED_MINES = 99;

const int BEGINNER_SIDE = 10;
const int INTERMADIATE_SIDE = 14;
const int ADVANCED_SIDE = 25;

const int MAX_SIDE = 200;

int SIDE = 0;
int MINES = 0;

const char CLOSED_SYMBOL = '-';
const char MINE_SYMBOL = '*';
const int OPENED_SYMBOL = 0;


void chooseDifficultyLevel();
void initBoard(int visibleBoard[][MAX_SIDE]);
void printBoard(int visibleBoard[][MAX_SIDE]);
void printMinesBoard(Mine minesBoard[]);
void placeMines(Mine minesBoard[ADVANCED_MINES]);
bool play(int visibleBoard[][MAX_SIDE], Mine minesBoard[ADVANCED_MINES], int row, int col);
bool isMine(Mine minesBoard[], int row, int col);
int countNeighbourMines(int visibleBoard[][MAX_SIDE], Mine minesBoard[ADVANCED_MINES], int row, int col);
bool isValid(int visibleBoard[][MAX_SIDE], int row, int col);

int main()
{
    srand(time(0));
    chooseDifficultyLevel();

    // Declare two two-dimensional arrays.
    // One to hold everything that is visible and change on every turn.
    // And Second to hold where the mines are, this one will not change after we place the mines.
    int visibleBoard[MAX_SIDE][MAX_SIDE];
    Mine minesBoard[MINES];

    initBoard(visibleBoard);

    // place mines inside minesBoard
    placeMines(minesBoard);
    // Think how to display Mines board
    printMinesBoard(minesBoard); // Print where the mines are (debug mode) (cheat mode)

    bool isGameOver = false;
    int row, col;
    while(!isGameOver) {
        printBoard(visibleBoard);
        cout << "Enter the coordinates (row col) of the square you want to open: ";
        cin >> row >> col;
        isGameOver = play(visibleBoard, minesBoard, row, col);

        if(isGameOver) {
            cout << "Your game is over!" << endl;
            printBoard(visibleBoard);
            break;
        }
    }

    return 0;
}

void printMinesBoard(Mine minesBoard[]) {
    cout << "   ";
    for(int colIndicator = 0; colIndicator < SIDE; colIndicator++){
        if(colIndicator < 10){
            cout << 0 << colIndicator << " ";
        } else {
            cout << colIndicator << " ";
        }

    }
    cout << endl;
    for(int row = 0; row < SIDE; row++) {
        if(row < 10){
            cout << 0 << row << " ";
        } else {
            cout << row << " ";
        }
        for(int col = 0; col < SIDE; col++) {
            // Check if the current element is dash(ascii code 45) or star(ascii code 42)
            if(isMine(minesBoard, row, col)) {
                cout << MINE_SYMBOL;
            }
            else {
                cout << CLOSED_SYMBOL;
            }
            cout << "  ";
        }
        cout << endl;
    }
}

bool isMine(Mine minesBoard[], int row, int col) {
    for(int i = 0; i < MINES; i++) {
        if(minesBoard[i].row == row && minesBoard[i].col == col) {
            return true;
        }
    }
    return false;
}

bool isValid(int visibleBoard[][MAX_SIDE], int row, int col){
    if((row >= 0 && row < SIDE) && (col >= 0 && col < SIDE)){
        return true;
    }
    return false;
}

// Counts how many mines the current cell has closeby
int countNeighbourMines(int visibleBoard[][MAX_SIDE], Mine minesBoard[], int row, int col){
    int count = 0; // MAX value is 8

    /*

    |r-1,c-1|r-1,c|r-1,c+1|
    | r,c-1 | r,c | r,c+1 |
    |r+1,c-1|r+1,c| r+1,c+|

    */

    if(isValid(visibleBoard, row-1, col-1) && isMine(minesBoard, row-1, col-1) == true) {
        count++;
    }

    if(isValid(visibleBoard, row-1, col) && isMine(minesBoard, row-1, col) == true) {
        count++;
    }

    if(isValid(visibleBoard, row-1, col+1) && isMine(minesBoard, row-1, col+1) == true) {
        count++;
    }

    if(isValid(visibleBoard, row, col-1) && isMine(minesBoard, row, col-1) == true) {
        count++;
    }

    if(isValid(visibleBoard, row, col+1) && isMine(minesBoard, row, col+1) == true) {
        count++;
    }

    if(isValid(visibleBoard, row+1, col-1) && isMine(minesBoard, row+1, col-1) == true) {
        count++;
    }

    if(isValid(visibleBoard, row+1, col) && isMine(minesBoard, row+1, col) == true) {
        count++;
    }

    if(isValid(visibleBoard, row+1, col+1) && isMine(minesBoard, row+1, col+1) == true) {
        count++;
    }

    return count;
}

// This is a recursive function
bool play(int visibleBoard[][MAX_SIDE], Mine minesBoard[], int row, int col) {
    // Continue the game
    // Expand neighbor areas with 0 bombs

    // checks if the current position is a mine and if yes=>returns true and stops the game.
    if(isMine(minesBoard, row, col) == true) {
        visibleBoard[row][col] = MINE_SYMBOL;
        return true; // GAME OVER
    }

    // checks if the current position has been opened before and if yes=>returns false and the game continues to the next move.
    if(visibleBoard[row][col] != CLOSED_SYMBOL) {
        return false;
    }

    // count how many mines the current position has closeby/nearby
    int count = countNeighbourMines(visibleBoard, minesBoard, row, col); // MIN = 0, MAX = 8
    if(count == 0) {
        visibleBoard[row][col] = OPENED_SYMBOL; // changes the current position to 0

        /*
            These if conditions check if the neighbor position is valid and if its a mine
        */

        // top-left
        if(isValid(visibleBoard, row-1, col-1) == true && isMine(minesBoard, row-1, col-1) == false){
            play(visibleBoard, minesBoard, row-1, col-1);
        }

        // top-center
        if(isValid(visibleBoard, row-1, col) == true && isMine(minesBoard, row-1, col) == false){
            play(visibleBoard, minesBoard, row-1, col);
        }

        // top-right
        if(isValid(visibleBoard, row-1, col+1) == true && isMine(minesBoard, row-1, col+1) == false){
            play(visibleBoard, minesBoard, row-1, col+1);
        }

        // left
        if(isValid(visibleBoard, row, col-1) == true && isMine(minesBoard, row, col-1) == false){
            play(visibleBoard, minesBoard, row, col-1);
        }

        // right
        if(isValid(visibleBoard, row, col+1) == true && isMine(minesBoard, row, col+1) == false){
            play(visibleBoard, minesBoard, row, col+1);
        }

        // bottom-left
        if(isValid(visibleBoard, row+1, col-1) == true && isMine(minesBoard, row+1, col-1) == false){
            play(visibleBoard, minesBoard, row+1, col-1);
        }

        // bottom-middle
        if(isValid(visibleBoard, row+1, col) == true && isMine(minesBoard, row+1, col) == false){
            play(visibleBoard, minesBoard, row+1, col);
        }

        // bottom-right
        if(isValid(visibleBoard, row+1, col+1) == true && isMine(minesBoard, row+1, col+1) == false){
            play(visibleBoard, minesBoard, row+1, col+1);
        }
        return false;
    } else {
        // changes the current position to the digit count
        visibleBoard[row][col] = count;
        return false;
    }
}

void placeMines(Mine minesBoard[]) {
    // For loop to place MINES mines
    for(int m = 0; m < MINES; ) {
        int random = 0 + rand() % (SIDE*SIDE); // generate random number from 0 to SIDE*SIDE
        int row = random / SIDE;
        int col = random % SIDE;

        // Check if there is already a mine on this position
        if(!isMine(minesBoard, row, col)) {
            minesBoard[m].row = row;
            minesBoard[m].col = col;
            m++;
        }


    }
}

void printBoard(int board[][MAX_SIDE]) {
    cout << "   ";
    for(int colIndicator = 0; colIndicator < SIDE; colIndicator++){
        if(colIndicator < 10){
            cout << 0 << colIndicator << " ";
        } else {
            cout << colIndicator << " ";
        }

    }
    cout << endl;
    for(int row = 0; row < SIDE; row++) {
        if(row < 10){
            cout << 0 << row << " ";
        } else {
            cout << row << " ";
        }
        for(int col = 0; col < SIDE; col++) {
            // Check if the current element is dash(ascii code 45) or star(ascii code 42)
            if(board[row][col] == 45 || board[row][col] == 42) {
                char el = board[row][col];
                cout << el;
            } else {
                cout << board[row][col];
            }
            cout << "  ";
        }
        cout << endl;
    }
}

// This function will put '-' on every position of the given array.
void initBoard(int visibleBoard[][MAX_SIDE]) {
    for(int row = 0; row < SIDE; row++) {
        for(int col = 0; col < SIDE; col++) {
            visibleBoard[row][col] = CLOSED_SYMBOL;
        }
    }
}

void chooseDifficultyLevel() {
    cout << "Choose your difficulty level: " << endl;
    cout << "0: BEGINNER 10x10 and 10 mines" << endl;
    cout << "1: INTERMEDIATE 14x14 and 40 mines" << endl;
    cout << "2: ADVANCED 25x25 and 99 mines" << endl;
    int choice;
    cin >> choice;

    switch(choice){
    case 0:
        SIDE = BEGINNER_SIDE;
        MINES = BEGINNER_MINES;
        cout << "You chose beginner level" << endl;
        break;
    case 1:
        SIDE = INTERMADIATE_SIDE;
        MINES = INTERMADIATE_MINES;
        cout << "You chose intermediate level" << endl;
        break;
    case 2:
        SIDE = ADVANCED_SIDE;
        MINES = ADVANCED_MINES;
        cout << "You chose advanced level" << endl;
        break;
    default:
        cout << "There is no such difficulty level! Try again!" << endl;
        break;
    }
}
