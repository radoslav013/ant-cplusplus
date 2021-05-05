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
    //s = (a+b+c)/2;
    // Input xa, ya, xb, yb
    double xa, ya, xb, yb, xc, yc;
    cout << "Enter x and y for point A: ";
    cin >> xa >> ya;

    cout << "Enter x and y for point B: ";
    cin >> xb >> yb;

    cout << "Enter x and y for point C: ";
    cin >> xc >> yc;

    double a = findDistance(xa, ya, xb, yb);
    double b = findDistance(xc, yc, xb, yb);
    double c = findDistance(xa, ya, xc, yc);

    cout << "The area of the triangle is: " << (a+b+c)/2 << endl;



    return 0;
}
