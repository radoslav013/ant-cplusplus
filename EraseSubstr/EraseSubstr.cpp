#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "Hello";
    string text2 = "Hello";
    cout << "Erase: " << text.erase(3) << endl;
    cout << "Substr: " << text2.substr(3) << endl;
    return 0;
}
