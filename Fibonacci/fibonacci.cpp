#include <iostream>

using namespace std;
/*
* Task Print Fibonacci sequence till 50
* 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
*/

int fibonacci(int i)
{

    if (i == 0 || i == 1)
    {
        return i;
    } else
    {
        cout << i << " ";
        cout << "fibonacci(i-1) " << fibonacci(i-1) << " ";
        cout << "fibonacci(i-2) " << fibonacci(i-2) << endl << endl;
        return fibonacci(i-1) + fibonacci(i-2);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        fibonacci(i);
    }

    return 0;
}
