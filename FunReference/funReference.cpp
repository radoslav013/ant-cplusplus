#include <iostream>

using namespace std;

void fun(int& x)
{
    x = 30;
}

int main()
{
    int y = 20;
    fun(y);
    cout << y << endl; // 30
    return 0;
}
