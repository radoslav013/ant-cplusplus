#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <winuser.h>
#include <ctime>

using namespace std;

const int MAP_ROWS=50;
const int MAP_COLS=50;
const char EMPTY_CHAR = ' ';

struct TPosition {
   int row = -1;
   int col = -1;
};

const int MAX_LEN = 25;
TPosition snake[MAX_LEN];
int s_len = 0;
int speed = 500;

HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screen_buf = {MAP_ROWS , MAP_COLS};

enum COLORS {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,

    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};

COLORS BGR_COLOR = WHITE;
COLORS SNAKE_COLOR = GREEN;

void draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color) {
    CHAR_INFO ch_info;
    ch_info.Char.AsciiChar = ch;
    ch_info.Attributes = foreground_color | (background_color << 4);

    COORD buf_size = {1, 1};
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);

}

void set_background(COLORS clr) {
    BGR_COLOR = clr;

    for(int r = 0; r < screen_buf.X; r++) {
        for(int c = 0; c < screen_buf.Y; c++) {
            draw_char(' ', r, c, BGR_COLOR, BGR_COLOR);
        }
    }
}

void drawBorders(COLORS clr) {
    for(int x = 0; x <= MAP_COLS; x++) {
        draw_char(EMPTY_CHAR, 0, x, BLACK, clr);
        draw_char(EMPTY_CHAR, MAP_ROWS, x, BLACK, clr);
    }

    for(int y = 0; y <= MAP_ROWS; y++) {
        draw_char(EMPTY_CHAR, y, 0, BLACK, clr);
        draw_char(EMPTY_CHAR, y, MAP_COLS, BLACK, clr);
    }
}

void setupConsole() {
    CONSOLE_FONT_INFOEX info = {0};
        info.cbSize       = sizeof(info);
        info.dwFontSize.X = 9;
        info.dwFontSize.Y = 9;
        info.FontWeight   = FW_NORMAL;
        wcscpy(info.FaceName, L"Terminal");
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

        SMALL_RECT DisplayArea = {0, 0, 0, 0};
         //set x and y to whatever ye' want
         int x = 50;
         int y = 50;

         DisplayArea.Right  = x;
         DisplayArea.Bottom = y;

         SetConsoleWindowInfo(hConsoleOutput, TRUE, &DisplayArea);
}

void drawSnake() {
    draw_char(EMPTY_CHAR, MAP_ROWS/2, MAP_COLS/2, SNAKE_COLOR, BLACK);
    snake[0] = { MAP_ROWS/2, MAP_COLS/2 };
    s_len++;
}

void drawFruits(int max_elements) {
   int br = 0;
   int rand_row, rand_col;

   while (br < max_elements) {
       rand_row = 1 + rand()%(MAP_ROWS-2);
       rand_col = 1 + rand()%(MAP_COLS-2);

       // TODO check the position so we don't put fruit
       // on top of the snake
       //if (board[rand_row][rand_col] == EMPTY_CHAR) {
           draw_char(EMPTY_CHAR, rand_row, rand_col, BLACK, RED);
           br++;
       //}
   }
}

void shift() {
    TPosition temp = snake[s_len-1], temp1;
    for (int i = 0; i < s_len; i++) {
        temp1 = snake[i];
        snake[i] = temp;
        temp = temp1;
    }
 }

char moveSnake(char prevDirection) {
    TPosition now;

    now.row = snake[s_len-1].row;
    now.col = snake[s_len-1].col;

    if (GetAsyncKeyState('W')) {
        prevDirection = 'W';
    }
    else if (GetAsyncKeyState('S')) {
        prevDirection = 'S';
    }
    else if (GetAsyncKeyState('A')) {
        prevDirection = 'A';
    }
    else if (GetAsyncKeyState('D')) {
        prevDirection = 'D';
    }
    // automatic directions
    switch(prevDirection) {
       case 'W': now.row--; break;
       case 'S': now.row++; break;
       case 'A': now.col--; break;
       case 'D': now.col++; break;
       default: now.col++; break;
    }


    // Delete tail
    draw_char(EMPTY_CHAR, snake[s_len-1].row, snake[s_len-1].col, BLACK, BGR_COLOR);
    snake[s_len-1] = { -1, -1 };

    // Shift snake array one position backwards
    shift();
    snake[0] = { now.row, now.col };
    draw_char(EMPTY_CHAR, now.row, now.col, SNAKE_COLOR, BLACK);

    // TODO: Check if apple eaten and if yes, increase snake's length by 1
    speed -= speed == 100 ? 0 : 20;

    // TODO: Check if snake ate itself

    // TODO: Check if snake hits the border and if yes ...

    return prevDirection;
}

int main() {
    srand(time(0));

    setupConsole();
    set_background(LIGHT_GREEN);
    // TODO: check why top-left corner has one black and one green squares
    drawBorders(YELLOW);
    drawFruits(20);

    // TODO OPTIONAL: Draw bombs which kill the snake
    // TODO OPTIONAL: Draw speeders to increase/decrease your speed
    drawSnake();

    char prevDirection = 'D';
    while(true) {
        prevDirection = moveSnake(prevDirection);
        Sleep(speed);
    }

    return 0;
}
