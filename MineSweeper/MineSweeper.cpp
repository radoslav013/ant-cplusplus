
#include <iostream>
#include <time.h>

using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE ; // side length of the board
int MINES ; // number of mines on the board
int movesLeft;

// A Function to print the current gameplay board
void printBoard(char myBoard[][MAXSIDE])
{
    int i, j;

    printf ("    ");

    for (i=0; i<SIDE; i++)
        printf ("%d ", i);

    printf ("\n\n");

    for (i=0; i<SIDE; i++)
    {
        printf ("%d   ", i);

        for (j=0; j<SIDE; j++)
            printf ("%c ", myBoard[i][j]);
        printf ("\n");
    }
    return;
}

// A Function to place the mines randomly
// on the board
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
    // Continue until all random mines have been created.
    for (int i=0; i<MINES; )
     {
        int random = rand() % (SIDE*SIDE);
        int x = random / SIDE;
        int y = random % SIDE;

        // Row Index of the Mine
        mines[i][0]= x;
        // Column Index of the Mine
        mines[i][1] = y;

        // Add the mine if no mine is placed at this
        // position on the board
        if (realBoard[mines[i][0]][mines[i][1]] != '*')
        {
            // Place the mine
            realBoard[mines[i][0]][mines[i][1]] = '*';
            i++;
        }
    }
}

// A Function to initialise the game
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{

    // Assign all the cells as mine-free
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
            myBoard[i][j] = realBoard[i][j] = '-';
        }
    }
}

// A Function to cheat by revealing where the mines are
// placed.
void cheatMinesweeper (char realBoard[][MAXSIDE])
{
    printf ("The mines locations are-\n");
    printBoard (realBoard);
}

// A Function to play Minesweeper game
void playMinesweeper ()
{
    // Initially the game is not over
    bool gameOver = false;

    // Actual Board and My Board
    char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

    movesLeft = SIDE * SIDE - MINES;
    int x, y;
    int mines[MAXMINES][2]; // stores (x,y) coordinates of all mines.

    initialise (realBoard, myBoard);

    // Place the Mines randomly
    placeMines (mines, realBoard);

     /*
     If you want to cheat and know
     where mines are before playing the game
     then uncomment this part
      */
     cheatMinesweeper(realBoard);
}

// A Function to choose the difficulty level
// of the game
void chooseDifficultyLevel ()
{
    /*
    --> BEGINNER = 9 * 9 Cells and 10 Mines
    --> INTERMEDIATE = 16 * 16 Cells and 40 Mines
    --> ADVANCED = 24 * 24 Cells and 99 Mines
    */

    int level;

    printf ("Enter the Difficulty Level\n");
    printf ("Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n");
    printf ("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n");
    printf ("Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n");

    scanf ("%d", &level);

    if (level == BEGINNER)
    {
        SIDE = 9;
        MINES = 10;
    }

    if (level == INTERMEDIATE)
    {
        SIDE = 16;
        MINES = 40;
    }

    if (level == ADVANCED)
    {
        SIDE = 24;
        MINES = 99;
    }

    return;
}

// Driver Program to test above functions
int main()
{
    // Initiate the random number generator so that
    // the same configuration doesn't arises
    srand(time (NULL));

    /* Choose a level between
    --> BEGINNER = 9 * 9 Cells and 10 Mines
    --> INTERMEDIATE = 16 * 16 Cells and 40 Mines
    --> ADVANCED = 24 * 24 Cells and 99 Mines
    */
    chooseDifficultyLevel ();

    playMinesweeper ();

    return (0);
}
