#include <iostream>
#include <string>

using namespace std;
//
int main()
{
    string input = "55 + 3 - 1 + 7 + 11 - 100";
    cout << input << endl;
    stringstream ss(input);

    int num;
    while(ss >> num) {
        // get the operator
    }

    // TODO: use stringstream
    int result = 14;
    return 0;
}
