#include <iostream>

using namespace std;

int main()
{
    int a = 10, *pa;
    pa = &a;
    int& ra = a;
    cout << "a=" << ra << endl;
    return 0;
}
