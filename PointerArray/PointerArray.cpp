#include <iostream>

using namespace std;

int main()
{
    int arri[] = { 1, 2, 3 };
    int* ptri = arri; // pointer to arri[0]

    char arrc[] = { 1, 2, 3 };
    char* ptrc = arrc; // pointer to arrc[0]

    cout << "sizeof arri[] = " << sizeof(arri) << endl;
    cout << "sizeof ptri = " <<  sizeof(ptri) << endl;

    cout << "sizeof arrc[] = " << sizeof(arrc) << endl;
    cout << "sizeof ptrc = " << sizeof(ptrc) << endl;

    return 0;
}
