#include <iostream>

using namespace std;

int main()
{
    int num[5]; // array num with 5 elements
    int* p; // declaring a pointer without initializing
    p = &num; // giving the address of num[0] to p
    *p = 10; // num[0] = 10
    p++; // equivalent to p = p + 1; p points to num[1]
    *p = 20; // num[1] = 20
    p = &num[2]; // p points to num[2]
    *p = 30; // num[2] = 30
    p = &num[0] + 3; // p points to num[3]
    *p = 40; // num[3] = 40
    p = num; // p points to num[0]
    *(p + 4) = 50; // num[4] = 50
    for (int i = 0; i < 5; i++)
        cout << num[i] << ", "; // Outputs: 10, 20, 30, 40, 50,
    return 0;
}
