#include <iostream>

using namespace std;
/*
* Enter a character and check if its from the latin alphabet
* lowercase
* uppercase
*/
int main()
{
    char latin;
    cin >> latin;

    if((latin >= 'a' && latin <= 'z') || (latin >= 'A' && latin <= 'Z')){
        cout << "It's a letter from the latin alphabet";
    } else {
        cout << "Not in the latin alphabet";
    }
    return 0;
}
