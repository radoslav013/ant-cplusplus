// C++ program for the coloring the
// background and text with
// different color
#include <iostream>

// Header file to change color of
// text and background
#include <windows.h>
using namespace std;

// Driver Code
int main()
{
	// Color of the console
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); // white background, black text

    // Print Statement
    cout << " Hello Geeks, "
        << "good night!!!";

    SetConsoleTextAttribute(console_color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); // default

    // Print Statement
    cout << " Hello Geeks, "
        << "good night!!!";



	return 0;
}
