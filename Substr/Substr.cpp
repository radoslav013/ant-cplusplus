#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "This is a string";
    string temp = text.substr(1);
    cout << temp << endl;
    return 0;
}

/*
n=5
24 12 6 48 12

n=4
24 12 6 12

n=3
24 12 6

n=2
24 6

n=1
6

n=0
6
*/
