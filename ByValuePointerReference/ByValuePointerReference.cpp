#include <iostream>

using namespace std;

void passParamByValue(int a) {
    a = 100;
}

void passParamByPointer(int *a){
    *a = 100;
}

void passParamByReference(int& a){
    a = 100;
}

int main()
{
    int b1 = 200;
    passParamByValue(b1);
    cout << b1 << endl;

    int b2 = 200;
    passParamByPointer(&b2);
    cout << b2 << endl;

    int b3 = 200;
    passParamByReference(b3);
    cout << b3 << endl;
    return 0;
}
