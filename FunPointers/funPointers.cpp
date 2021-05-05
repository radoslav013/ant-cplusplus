#include <iostream>

using namespace std;

void fun(int* x, int* y){
    int p;
    p = *x;
    *x = 3;
    *y = p;

    cout << "f a = " << *x << endl;
    cout << "f b = " << *y << endl;
}
int main()
{
    int a = 1;
    int b = 2;
    cout << "main a = " << a << endl;
    cout << "main b = " << b << endl;
    fun(&a, &b);
    fun(&b, &a);
    cout << "main a = " << a << endl;
    cout << "main b = " << b << endl;
    return 0;
}
