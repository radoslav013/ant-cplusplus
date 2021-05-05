#include <iostream>

using namespace std;

int main()
{
    int n;
    do {
        cout << "Enter a natural number(n > 0): ";
        cin >> n;
    } while(n <= 0);

    cout << "Great! Your number is valid!";
    return 0;
}
