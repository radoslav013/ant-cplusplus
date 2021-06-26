#include <iostream>

#include <windows.h>

using namespace std;

const int ROWS = 30;
const int COLS = 75;

char board[ROWS][COLS];

struct TPosition {
   int row = -1;
   int col = -1;
};

const int MAX_LEN = 25;
TPosition snake[MAX_LEN];
int s_len = 0;



const char EMPTY_CH = ' ';
const char BORDER_CH = '*';
const char APPLE_CH = '@';
const char SNAKE_CH = 'o';
const char DEAD_SNAKE_CH = '#';

void printBoard() {
   system("cls");
   for (int r = 0; r < ROWS; r++) {
       for (int c = 0; c < COLS; c++) {
           cout << board[r][c];
       }
       cout << endl;
   }
   Sleep(100);
}

void printBorder() {
   for (int r = 0; r < ROWS; r++) {
       for (int c = 0; c < COLS; c++) {
           if ((r == 0) || (r == ROWS-1) ||
               (c == 0) || (c == COLS-1)) {
                   board[r][c] = BORDER_CH;
           }
           else {
               board[r][c] = EMPTY_CH;
           }
       }
   }
}

void putElement(char el, int max_elements) {
   int br = 0;
   int rand_row, rand_col;

   while (br < max_elements) {
       rand_row = 1 + rand()%(ROWS-2);
       rand_col = 1 + rand()%(COLS-2);

       if (board[rand_row][rand_col] == EMPTY_CH) {
           board[rand_row][rand_col] = el;
           br++;
       }
   }
}

void putSnake() {
   for (int s = 0; s < s_len; s++) {
       board[snake[s].row][snake[s].col] = SNAKE_CH;
   }
}

char moveSnake(char prevDirection = 'd') {
   TPosition now;

   now.row = snake[s_len-1].row;
   now.col = snake[s_len-1].col;

   if (GetAsyncKeyState(VK_UP)) {
       now.row--;
       prevDirection = 'w';
   }
   else if (GetAsyncKeyState(VK_DOWN)) {
       now.row++;
       prevDirection = 's';
   }
   else if (GetAsyncKeyState(VK_LEFT)) {
       now.col--;
       prevDirection = 'a';
   }
   else if (GetAsyncKeyState(VK_RIGHT)) {
       now.col++;
       prevDirection = 'd';
   }
   else {
       // automatic directions
       switch(prevDirection) {
           case 'w': now.row--; break;
           case 's': now.row++; break;
           case 'a': now.col--; break;
           case 'd': now.col++; break;
           default: now.col++; break;
       }
   }

   // check if the snake eat its tail
   if ((now.row == snake[s_len-1].row) &&
       (now.col == snake[s_len-1].col)) {
           return 'z';
   }

   // check if the position is an apple
   if (board[now.row][now.col] == APPLE_CH) {
       s_len++;
       putElement(APPLE_CH, 1);
   }
   // moves the snake
   else if (board[now.row][now.col] == EMPTY_CH){
       board[snake[0].row][snake[0].col] = EMPTY_CH;
       for (int s = 0; s < s_len-1; s++) {
           snake[s].row = snake[s+1].row;
           snake[s].col = snake[s+1].col;
       }
   // in case of a bite, put death char
   } else if(snake[s_len-2].row == now.row && snake[s_len-2].col == now.col) {
       return 'z';
   }
   else {
        board[now.row][now.col] = DEAD_SNAKE_CH;
        snake[s_len-1].row = now.row;
        snake[s_len-1].col = now.col;
        return 'z';
   }

   snake[s_len-1].row = now.row;
   snake[s_len-1].col = now.col;
   board[now.row][now.col] = SNAKE_CH;
   return prevDirection;
}

int main() {
   srand(time(0));

   printBorder();

   s_len = 1;
   snake[0].row = ROWS/2;
   snake[0].col = COLS/2;

   putSnake();
   putElement(APPLE_CH, 20);

   char prevDirection = 'd';
   while (1) {
       char currDirrection = moveSnake(prevDirection);
       if(currDirrection != 'z'){
           prevDirection = currDirrection;
       }
       printBoard();

       if (board[snake[s_len-1].row][snake[s_len-1].col] == DEAD_SNAKE_CH) {
           cout << "GAME OVER!" << endl;
           break;
       }

       if (s_len == MAX_LEN) {
           cout << "YOU WIN!" << endl;
           break;
       }
   }

   //Sleep(100);
   return 0;
}
