#include <iostream>

using namespace std;

int main()
{
    float x = 5.999;
    float* y, *z;
    y = &x;
    z = y;
    cout << x << ", " << *(&x) << ", " << *y << ", " << *z << "\n";
    // Outputs: 5.999, 5.999, 5.999, 5.999
    return 0;
}
