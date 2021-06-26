#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <winuser.h>
#include <time.h>
using namespace std;

const int MAP_ROWS=100;
const int MAP_COLS=100;

int score = 0;


HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screen_buf = {MAP_ROWS , MAP_COLS};
CHAR_INFO blank_screen[MAP_ROWS * MAP_COLS] = {0};


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

int main () {
    set_background(RED);
    COLORS clr = WHITE;

    int row = 0;
    int col = 0;

    int st_row = MAP_ROWS / 2;
    int st_col = MAP_COLS / 2;

    while(true) {
        draw_char(' ', st_row - row, st_col - col, clr, clr);
        draw_char(' ', st_row + row, st_col + col, clr, clr);

        draw_char(' ', st_row - col, st_col - row, clr, clr);
        draw_char(' ', st_row + col, st_col + row, clr, clr);

        if (GetAsyncKeyState('W')) {row--;}
        if (GetAsyncKeyState('S')) {row++;}
        if (GetAsyncKeyState('A')) {col--;}
        if (GetAsyncKeyState('D')) {col++;}
        if (GetAsyncKeyState('B')) {clr = BGR_COLOR;}

        if(GetAsyncKeyState(VK_TAB)) {
            clr = (COLORS)(((int)clr + 1) % 16);
        }

        Sleep(50);
    }

    return 0;
}
