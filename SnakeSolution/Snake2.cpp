#include <iostream>
#include <time.h>

using namespace std;

const int ROWS_LENGTH = 25;
const int COLS_LENGTH = 50;

const char BORDER_SYMBOL = '*';
const char EMPTY_SYMBOL = ' ';
const char FRUIT_SYMBOL = '@';

char board[ROWS_LENGTH][COLS_LENGTH];

void putFruits(int count) {
    int randRow, randCol;
    for(int i = 0; i < count; i++){
        randRow = rand() % (ROWS_LENGTH-2) + 1;
        randCol = rand() % (COLS_LENGTH-2) + 1;
        board[randRow][randCol] = FRUIT_SYMBOL;
    }
}

void initBoard() {
    for(int i = 0; i < ROWS_LENGTH; i++)
    {
        for(int j = 0; j < COLS_LENGTH; j++)
        {
            if((i == 0 || i == ROWS_LENGTH - 1) || (j == 0 || j == COLS_LENGTH - 1)) {
                board[i][j] = BORDER_SYMBOL;
            } else  {
                board[i][j] = EMPTY_SYMBOL;
            }
        }
    }
}

void printBoard() {
    for(int i = 0; i < ROWS_LENGTH; i++)
    {
        for(int j = 0; j < COLS_LENGTH; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    initBoard();
    putFruits(10);
    printBoard();
    return 0;
}


// Task: Snake Game
// 1. Draw borders. // DONE
// 2. Draw fruits // DONE
// 3. Draw snake // TODO
// 4. Move the snake with the keyboard arrows // TODO
// 5. Redraw the board on every movement // TODO
// 6. Check if the new position of the snake is a border symbol or fruit symbol or the snake itself
