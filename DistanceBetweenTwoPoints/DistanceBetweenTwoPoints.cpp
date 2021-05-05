#include <iostream>
#include <cmath>

using namespace std;

double findDistance(double xa, double ya, double xb, double yb) {
    double a = xa-xb;
    double b = ya-yb;
    return sqrt(a*a+b*b);
}

int main()
{
    // Input xa, ya, xb, yb
    double xa, ya, xb, yb;
    cout << "Enter x and y for point A: ";
    cin >> xa >> ya;

    cout << "Enter x and y for point B: ";
    cin >> xb >> yb;

    int dist = findDistance(xa, ya, xb, yb);
    cout << "The distance between those two points is " << dist << endl;
    return 0;
}
