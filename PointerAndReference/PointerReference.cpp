#include <iostream>

using namespace std;

int main()
{
    // Pointer
    int a = 100;
    int *p;
    p = &a;

    // Reference
    int b = 200;
    int &r = b;

    r = 400;
    cout << r << " " << b;
    return 0;
}
